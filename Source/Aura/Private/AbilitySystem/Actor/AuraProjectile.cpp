// Thomas Learning Project

#include "AbilitySystem/Actor/AuraProjectile.h"

#include "GameFramework/ProjectileMovementComponent.h"

AAuraProjectile::AAuraProjectile()
{
	PrimaryActorTick.bCanEverTick = false;

	PrimaryActorTick.bStartWithTickEnabled = false;

	PrimaryActorTick.bAllowTickOnDedicatedServer = false;

	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>("ProjectileMovementComponent");
}

const AAuraProjectile* AAuraProjectile::CreateProjectile(const UObject* WorldContextObject, TSubclassOf<AAuraProjectile> ProjectileClass, AActor* OwningActor, const FVector& SpawnLocation, const FVector& TargetLocation)
{
	const FVector Direction = (TargetLocation - SpawnLocation);

	FTransform SpawnTransform = FTransform(Direction.Rotation().Quaternion());
	SpawnTransform.SetLocation(SpawnLocation);
	
	AAuraProjectile* ProjectileInstance = WorldContextObject->GetWorld()->SpawnActorDeferred<AAuraProjectile>(ProjectileClass, SpawnTransform, OwningActor);

	ProjectileInstance->FinishSpawning(SpawnTransform);

	return ProjectileInstance;
}

void AAuraProjectile::OnProjectileOverlap(AActor* OtherActor)
{



	Destroy();
}
