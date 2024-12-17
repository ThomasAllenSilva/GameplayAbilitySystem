// Thomas Learning Project

#pragma once

#include "CoreMinimal.h"

#include "Abilities/GameplayAbility.h"

#include "AuraGameplayAbility.generated.h"

/**
 * 
 */
UCLASS()
class UAuraGameplayAbility final : public UGameplayAbility
{
	GENERATED_BODY()
	

public:
	FGameplayTag InputTag;
};
