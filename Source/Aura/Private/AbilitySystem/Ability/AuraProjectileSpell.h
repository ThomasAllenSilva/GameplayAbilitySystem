// Thomas Learning Project

#pragma once

#include "CoreMinimal.h"

#include "AbilitySystem/Ability/AuraGameplayAbility.h"

#include "AuraProjectileSpell.generated.h"

/**
 * 
 */

class AAuraProjectile;

UCLASS()
class UAuraProjectileSpell final : public UAuraGameplayAbility
{
	GENERATED_BODY()
	
protected:
	UFUNCTION(BlueprintCallable)
	void SpawnProjectile(const FVector& TargetLocation);

private:
	UPROPERTY(BlueprintReadOnly, meta = (AllowPrivateAccess))
	TSubclassOf<UGameplayEffect> SpellEffect;

	UPROPERTY(BlueprintReadOnly, meta = (AllowPrivateAccess))
	TSubclassOf<AAuraProjectile> ProjectileClass;
};
