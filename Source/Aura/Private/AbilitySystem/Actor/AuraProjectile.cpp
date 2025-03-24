// Thomas Learning Project

#include "AbilitySystem/Actor/AuraProjectile.h"
#include "Characters/Base/AuraCharacterBase.h"
#include "NiagaraFunctionLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystemComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "AuraNativeGameplayTags.h"

#include "Debug.h"

AAuraProjectile::AAuraProjectile()
{
	PrimaryActorTick.bCanEverTick = false;

	PrimaryActorTick.bStartWithTickEnabled = false;

	PrimaryActorTick.bAllowTickOnDedicatedServer = false;

	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>("ProjectileMovementComponent");
}

const AAuraProjectile* AAuraProjectile::CreateProjectile(const UObject* WorldContextObject, TSubclassOf<AAuraProjectile> ProjectileClass, AActor* OwningActor, const FVector& TargetLocation, const FVector& SpawnLocation, const TArray<FGameplayEffectSpecHandle>& EffectSpecHandle)
{
	const FVector Direction = (TargetLocation - SpawnLocation);

	FRotator Rotation = Direction.Rotation();

	FTransform SpawnTransform;

	SpawnTransform.SetLocation(SpawnLocation);
	SpawnTransform.SetRotation(Rotation.Quaternion());

	AAuraProjectile* ProjectileInstance = WorldContextObject->GetWorld()->SpawnActorDeferred<AAuraProjectile>(ProjectileClass, SpawnTransform, OwningActor);

	ProjectileInstance->EffectsSpecHandle = EffectSpecHandle;

	ProjectileInstance->FinishSpawning(SpawnTransform);

	return ProjectileInstance;
}

void AAuraProjectile::BeginPlay()
{
	Super::BeginPlay();

	checkf(AttachedSpawnSound, TEXT("Invalid Or Null Spawn Sound For Projectile"));

	UGameplayStatics::SpawnSoundAttached(AttachedSpawnSound, GetRootComponent(), NAME_None, FVector::ZeroVector, EAttachLocation::KeepRelativeOffset, true);
}

void AAuraProjectile::ApplyProjectileEffectToTarget(AActor* TargetActor)
{
	checkf(CollisionEffect, TEXT("Invalid Or Null Collision Effect For Projectile"));

	checkf(CollisionSound, TEXT("Invalid Or Null Collision Sound For Projectile"));

	UGameplayStatics::PlaySoundAtLocation(this, CollisionSound, GetActorLocation());

	UNiagaraFunctionLibrary::SpawnSystemAtLocation(this, CollisionEffect, GetActorLocation());

	if (UAbilitySystemComponent* ASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(TargetActor))
	{
		for (FGameplayEffectSpecHandle& EffectSpecHandle : EffectsSpecHandle)
		{
			ASC->ApplyGameplayEffectSpecToSelf(*EffectSpecHandle.Data.Get());

			FGameplayTagContainer TagContainer;

			EffectSpecHandle.Data.Get()->GetAllAssetTags(TagContainer);
			for (const FGameplayTag& GameplayTag : TagContainer)
			{
				if (GameplayTag.MatchesTag(Common_Event))
				{
					FGameplayEventData EventData;

					UAbilitySystemBlueprintLibrary::SendGameplayEventToActor(TargetActor, GameplayTag, EventData);
				}
			}
		}
	}

	Destroy();
}
