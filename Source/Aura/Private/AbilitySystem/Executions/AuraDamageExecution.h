// Thomas Learning Project

#pragma once

#include "CoreMinimal.h"
#include "GameplayEffectExecutionCalculation.h"
#include "AuraDamageExecution.generated.h"

struct FAuraGameplayEffectContext;

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

	void CalculateBlockChance(float BlockChanceMagnitude, float& OutDamage, FAuraGameplayEffectContext* EffectContext) const;

	void CalculateArmorPenetration(float TargetAmor, float SourceArmorPenetration, float& OutDamage) const;

	void CalculateCriticalHit(float SourceCriticalHitChance, float TargetCriticalHitResistance, float CriticalHitDamage, float& OutDamage, FAuraGameplayEffectContext* EffectContext) const;
};
