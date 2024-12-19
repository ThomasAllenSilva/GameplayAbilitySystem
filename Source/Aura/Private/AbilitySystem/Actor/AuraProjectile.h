// Thomas Learning Project

#pragma once

#include "CoreMinimal.h"

#include "GameFramework/Actor.h"

#include "AuraProjectile.generated.h"

class UProjectileMovementComponent;

UCLASS()
class AAuraProjectile final : public AActor
{
	GENERATED_BODY()

public:
	AAuraProjectile();

	UFUNCTION(BlueprintCallable, Category = "Projectile", meta = (HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	static const AAuraProjectile* CreateProjectile(const UObject* WorldContextObject, TSubclassOf<AAuraProjectile> ProjectileClass, AActor* OwningActor, const FVector& SpawnLocation, const FVector& TargetLocation);

private:
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UProjectileMovementComponent> ProjectileMovementComponent;
};
