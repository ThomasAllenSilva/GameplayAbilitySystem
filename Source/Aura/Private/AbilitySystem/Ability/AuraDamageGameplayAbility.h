// Thomas Learning Project

#pragma once

#include "CoreMinimal.h"
#include "Ability/CommonGameplayAbility.h"
#include "GameplayTagContainer.h"
#include "AuraDamageGameplayAbility.generated.h"

/**
 * The base gameplay ability class for abilities that can cause damage. 
 * It holds information about damage effects and damage types (Fire, Arcane, etc).
 * It also specifies other effects that this ability can carry along.
 */
UCLASS(Abstract)
class UAuraDamageGameplayAbility : public UCommonGameplayAbility
{
	GENERATED_BODY()
	
protected:
	/* Effects that are used specifically for causing damage */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TArray<TSubclassOf<UGameplayEffect>> DamageEffects;

	/* The scalable magnitude to apply on the damage type. Applied on each Damage Effect */
	UPROPERTY(EditDefaultsOnly)
	TMap<FGameplayTag, FScalableFloat> DamageTypes;

	/* Additional effects that are not necessarily about applying damage */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TArray<TSubclassOf<UGameplayEffect>> OtherEffects;
};
