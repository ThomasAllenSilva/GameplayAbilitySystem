// Thomas Learning Project

#pragma once

#include "CoreMinimal.h"
#include "AuraDamageGameplayAbility.h"
#include "AuraProjectileSpell.generated.h"

/**
 * 
 */

class AAuraProjectile;

UCLASS()
class UAuraProjectileSpell final : public UAuraDamageGameplayAbility
{
	GENERATED_BODY()
	
protected:
	UFUNCTION(BlueprintCallable)
	void SpawnProjectile(const FVector& TargetLocation);

private:
	UPROPERTY(BlueprintReadOnly, meta = (AllowPrivateAccess))
	TSubclassOf<AAuraProjectile> ProjectileClass;
};
