// Thomas Learning Project

#include "AbilitySystem/Actor/AuraProjectile.h"

#include "AbilitySystem/Interfaces/CombatInterface.h"

#include "NiagaraFunctionLibrary.h"

#include "Kismet/GameplayStatics.h"

#include "GameFramework/ProjectileMovementComponent.h"

AAuraProjectile::AAuraProjectile()
{
	PrimaryActorTick.bCanEverTick = false;

	PrimaryActorTick.bStartWithTickEnabled = false;

	PrimaryActorTick.bAllowTickOnDedicatedServer = false;

	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>("ProjectileMovementComponent");
}

const AAuraProjectile* AAuraProjectile::CreateProjectile(const UObject* WorldContextObject, TSubclassOf<AAuraProjectile> ProjectileClass, AActor* OwningActor, const FVector& TargetLocation)
{
	FVector SpawnLocation = OwningActor->GetActorLocation();

	if (ICombatInterface* CombatInterface = Cast<ICombatInterface>(OwningActor))
	{
		SpawnLocation = CombatInterface->GetProjectileSpawnLocation();
	}

	const FVector Direction = (TargetLocation - SpawnLocation);

	FRotator Rotation = Direction.Rotation();

	FTransform SpawnTransform = FTransform(Rotation.Quaternion());

	SpawnTransform.SetLocation(SpawnLocation);

	AAuraProjectile* ProjectileInstance = WorldContextObject->GetWorld()->SpawnActorDeferred<AAuraProjectile>(ProjectileClass, SpawnTransform, OwningActor);

	ProjectileInstance->FinishSpawning(SpawnTransform);

	return ProjectileInstance;
}

void AAuraProjectile::BeginPlay()
{
	Super::BeginPlay();

	checkf(AttachedSpawnSound, TEXT("Invalid Or Null Spawn Sound For Projectile"));

	UGameplayStatics::SpawnSoundAttached(AttachedSpawnSound, GetRootComponent(), NAME_None, FVector::ZeroVector, EAttachLocation::KeepRelativeOffset, true);
}

void AAuraProjectile::OnProjectileOverlap(AActor* OtherActor)
{
	checkf(CollisionEffect, TEXT("Invalid Or Null Collision Effect For Projectile"));

	checkf(CollisionEffect, TEXT("Invalid Or Null Collision Sound For Projectile"));

	UGameplayStatics::PlaySoundAtLocation(this, CollisionSound, GetActorLocation());

	UNiagaraFunctionLibrary::SpawnSystemAtLocation(this, CollisionEffect, GetActorLocation());

	Destroy();
}

