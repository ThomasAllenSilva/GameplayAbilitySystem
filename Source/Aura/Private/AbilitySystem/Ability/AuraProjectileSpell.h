// Thomas Learning Project

#pragma once

#include "CoreMinimal.h"
#include "AuraDamageGameplayAbility.h"
#include "AuraProjectileSpell.generated.h"

class AAuraProjectile;

/**
 * Gameplay ability used for spawning projectiles that carry gameplay effects
 */
UCLASS()
class UAuraProjectileSpell final : public UAuraDamageGameplayAbility
{
	GENERATED_BODY()
	
protected:
	UFUNCTION(BlueprintCallable)
	void SpawnProjectile(const FVector& TargetLocation);

	UFUNCTION(BlueprintImplementableEvent)
	FVector GetProjectileSpawnLocation() const;

private:
	UPROPERTY(BlueprintReadOnly, meta = (AllowPrivateAccess))
	TSubclassOf<AAuraProjectile> ProjectileClass;
};
