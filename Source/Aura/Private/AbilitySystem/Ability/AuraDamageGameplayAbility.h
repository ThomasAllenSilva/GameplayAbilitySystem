// Thomas Learning Project

#pragma once

#include "CoreMinimal.h"
#include "Base/AuraGameplayAbility.h"
#include "GameplayTagContainer.h"
#include "AuraDamageGameplayAbility.generated.h"

/**
 * The base gameplay ability class for abilities that can cause damage. 
 * It holds information about damage effects and damage types (Fire, Arcane, etc).
 * It also specifies other effects that this ability can carry along.
 */
UCLASS(Abstract)
class UAuraDamageGameplayAbility : public UAuraGameplayAbility
{
	GENERATED_BODY()
	
protected:
	UFUNCTION(BlueprintCallable)
	void ApplyDamage(AActor* TargetActor);

	TArray<FGameplayEffectSpecHandle> GetAbilityEffectsSpecs();

protected:
	/* Effect that is used specifically for causing damage */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<UGameplayEffect> DamageEffect;

	/* The scalable magnitude to apply on the damage type. Applied on the Damage Effect */
	UPROPERTY(EditDefaultsOnly)
	TMap<FGameplayTag, FScalableFloat> DamageTypes;

	/* Additional effects that are not necessarily about applying damage */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TArray<TSubclassOf<UGameplayEffect>> OtherEffects;
};
