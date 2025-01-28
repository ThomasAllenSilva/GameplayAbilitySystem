// Thomas Learning Project


#include "AuraDamageExecution.h"

#include "AbilitySystem/AttributeSet/AuraSecondaryAttributeSet.h"

#include "AbilitySystem/AttributeSet/AuraMetaAttributeSet.h"

#include "AuraNativeGameplayTags.h"

struct FDamageStatics
{
	DECLARE_ATTRIBUTE_CAPTUREDEF(Armor)

	DECLARE_ATTRIBUTE_CAPTUREDEF(BlockChance)

	FDamageStatics()
	{
		DEFINE_ATTRIBUTE_CAPTUREDEF(UAuraSecondaryAttributeSet, Armor, Target, false);

		DEFINE_ATTRIBUTE_CAPTUREDEF(UAuraSecondaryAttributeSet, BlockChance, Target, false);
	}
};

static const FDamageStatics& DamageStatics()
{
	static FDamageStatics Statics;

	return Statics;
}

UAuraDamageExecution::UAuraDamageExecution()
{
	const FDamageStatics& DamageStatic = DamageStatics();

	RelevantAttributesToCapture.Add(DamageStatic.ArmorDef);
}

void UAuraDamageExecution::Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams, FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const
{
	const FDamageStatics& DamageStatic = DamageStatics();

	ExecutionParams.GetSourceAbilitySystemComponent();

	const FGameplayEffectSpec& Spec = ExecutionParams.GetOwningSpec();

	const FGameplayTagContainer* SourceTags = Spec.CapturedSourceTags.GetAggregatedTags();
	const FGameplayTagContainer* TargetTags = Spec.CapturedTargetTags.GetAggregatedTags();

	FAggregatorEvaluateParameters EvaluateParameters;
	EvaluateParameters.SourceTags = SourceTags;
	EvaluateParameters.TargetTags = TargetTags;

	float DamageMagnitude = Spec.GetSetByCallerMagnitude(Damage);

	float BlockChanceMagnitude = GetCalculatedCapturedAttributeMagnitude(ExecutionParams, DamageStatic.BlockChanceDef, EvaluateParameters);


	//Successful Block. Maybe sending a Gameplay Event here to the target actor could help display damage texts?
	if (FMath::RandRange(UE_KINDA_SMALL_NUMBER, 100.0f) <= BlockChanceMagnitude)
	{
		DamageMagnitude *= 0.5f;
	}

	const FGameplayModifierEvaluatedData DamageModifierEvaluatedData(UAuraMetaAttributeSet::GetBaseDamageAttribute(), EGameplayModOp::Additive, DamageMagnitude);

	OutExecutionOutput.AddOutputModifier(DamageModifierEvaluatedData);
}

float UAuraDamageExecution::GetCalculatedCapturedAttributeMagnitude(const FGameplayEffectCustomExecutionParameters& ExecutionParams, const FGameplayEffectAttributeCaptureDefinition& AttributeCaptureDefinition, const FAggregatorEvaluateParameters& EvaluateParameters) const
{
	float AttributeMagnitude;

	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(AttributeCaptureDefinition, EvaluateParameters, AttributeMagnitude);

	return AttributeMagnitude;
}
