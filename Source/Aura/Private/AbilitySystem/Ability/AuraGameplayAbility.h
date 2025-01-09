// Thomas Learning Project

#pragma once

#include "CoreMinimal.h"

#include "Abilities/GameplayAbility.h"

#include "AuraGameplayAbility.generated.h"

/**
 * 
 */
UCLASS()
class UAuraGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()
	

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	FGameplayTag InputTag;
};
