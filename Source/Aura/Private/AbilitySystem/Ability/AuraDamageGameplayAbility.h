// Thomas Learning Project

#pragma once

#include "CoreMinimal.h"
#include "Ability/CommonGameplayAbility.h"
#include "GameplayTagContainer.h"
#include "AuraDamageGameplayAbility.generated.h"

/**
 * Base class for abilties that cause damage 
 */
UCLASS(Abstract)
class UAuraDamageGameplayAbility : public UCommonGameplayAbility
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TArray<TSubclassOf<UGameplayEffect>> DamageEffects;

	UPROPERTY(EditDefaultsOnly)
	TMap<FGameplayTag, FScalableFloat> DamageTypes;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TArray<TSubclassOf<UGameplayEffect>> OtherEffects;
};
