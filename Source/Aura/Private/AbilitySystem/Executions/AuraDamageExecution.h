// Thomas Learning Project

#pragma once

#include "CoreMinimal.h"
#include "GameplayEffectExecutionCalculation.h"
#include "AuraDamageExecution.generated.h"

/**
 * 
 */
UCLASS()
class UAuraDamageExecution final : public UGameplayEffectExecutionCalculation
{
	GENERATED_BODY()
	
public:
	UAuraDamageExecution();

	virtual void Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams, FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const override;
};
