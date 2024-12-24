// Thomas Learning Project

#include "AbilitySystem/Actor/AuraProjectile.h"

#include "AbilitySystem/Interfaces/CombatInterface.h"

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

	Rotation.Pitch = 0.0f;

	FTransform SpawnTransform = FTransform(Rotation.Quaternion());

	SpawnTransform.SetLocation(SpawnLocation);

	AAuraProjectile* ProjectileInstance = WorldContextObject->GetWorld()->SpawnActorDeferred<AAuraProjectile>(ProjectileClass, SpawnTransform, OwningActor);

	ProjectileInstance->FinishSpawning(SpawnTransform);

	return ProjectileInstance;
}

void AAuraProjectile::OnProjectileOverlap(AActor* OtherActor)
{



	Destroy();
}
