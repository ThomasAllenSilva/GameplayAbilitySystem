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

private:
	float GetCalculatedCapturedAttributeMagnitude(const FGameplayEffectCustomExecutionParameters& CustomExecutionParameters, const FGameplayEffectAttributeCaptureDefinition& AttributeCaptureDefinition, const FAggregatorEvaluateParameters& EvaluateParameters) const;

	void CalculateBlockChance(float BlockChanceMagnitude, float& OutDamage) const;

	void CalculateArmorPenetration(float TargetAmor, float SourceArmorPenetration, float& OutDamage) const;

	void CalculateCriticalHit(float SourceCriticalHitChance, float TargetCriticalHitResistance, float CriticalHitDamage, float& OutDamage) const;
};
