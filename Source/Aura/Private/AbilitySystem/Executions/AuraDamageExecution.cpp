// Thomas Learning Project


#include "AuraDamageExecution.h"

#include "AbilitySystem/AttributeSets/AuraSecondaryAttributeSet.h"

#include "AbilitySystem/AttributeSets/AuraMetaAttributeSet.h"

#include "AuraNativeGameplayTags.h"

struct FDamageStatics
{
	DECLARE_ATTRIBUTE_CAPTUREDEF(Armor)

	DECLARE_ATTRIBUTE_CAPTUREDEF(ArmorPenetration)

	DECLARE_ATTRIBUTE_CAPTUREDEF(BlockChance)

	DECLARE_ATTRIBUTE_CAPTUREDEF(CriticalHitChance)

	DECLARE_ATTRIBUTE_CAPTUREDEF(CriticalHitResistance)

	DECLARE_ATTRIBUTE_CAPTUREDEF(CriticalHitDamage)

	FDamageStatics()
	{
		DEFINE_ATTRIBUTE_CAPTUREDEF(UAuraSecondaryAttributeSet, Armor, Target, false);

		DEFINE_ATTRIBUTE_CAPTUREDEF(UAuraSecondaryAttributeSet, ArmorPenetration, Target, false);

		DEFINE_ATTRIBUTE_CAPTUREDEF(UAuraSecondaryAttributeSet, BlockChance, Target, false);

		DEFINE_ATTRIBUTE_CAPTUREDEF(UAuraSecondaryAttributeSet, CriticalHitChance, Source, false);

		DEFINE_ATTRIBUTE_CAPTUREDEF(UAuraSecondaryAttributeSet, CriticalHitResistance, Target, false);

		DEFINE_ATTRIBUTE_CAPTUREDEF(UAuraSecondaryAttributeSet, CriticalHitDamage, Source, false);
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

	RelevantAttributesToCapture.Add(DamageStatic.ArmorPenetrationDef);

	RelevantAttributesToCapture.Add(DamageStatic.BlockChanceDef);

	RelevantAttributesToCapture.Add(DamageStatic.CriticalHitChanceDef);

	RelevantAttributesToCapture.Add(DamageStatic.CriticalHitResistanceDef);

	RelevantAttributesToCapture.Add(DamageStatic.CriticalHitDamageDef);
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

	float TargetArmorMagnitude = GetCalculatedCapturedAttributeMagnitude(ExecutionParams, DamageStatic.ArmorDef, EvaluateParameters);

	float SourceArmorPenetrationMagnitude = GetCalculatedCapturedAttributeMagnitude(ExecutionParams, DamageStatic.ArmorPenetrationDef, EvaluateParameters);

	float SourceCriticalHitChance = GetCalculatedCapturedAttributeMagnitude(ExecutionParams, DamageStatic.CriticalHitChanceDef, EvaluateParameters);

	float TargetCriticalHitResistance = GetCalculatedCapturedAttributeMagnitude(ExecutionParams, DamageStatic.CriticalHitResistanceDef, EvaluateParameters);

	float SourceCriticalHitDamage = GetCalculatedCapturedAttributeMagnitude(ExecutionParams, DamageStatic.CriticalHitDamageDef, EvaluateParameters);

	CalculateBlockChance(BlockChanceMagnitude, DamageMagnitude);

	CalculateArmorPenetration(TargetArmorMagnitude, SourceArmorPenetrationMagnitude, DamageMagnitude);

	CalculateCriticalHit(SourceCriticalHitChance, TargetCriticalHitResistance, SourceCriticalHitDamage, DamageMagnitude);

	const FGameplayModifierEvaluatedData DamageModifierEvaluatedData(UAuraMetaAttributeSet::GetBaseDamageAttribute(), EGameplayModOp::Additive, DamageMagnitude);

	OutExecutionOutput.AddOutputModifier(DamageModifierEvaluatedData);
}

float UAuraDamageExecution::GetCalculatedCapturedAttributeMagnitude(const FGameplayEffectCustomExecutionParameters& ExecutionParams, const FGameplayEffectAttributeCaptureDefinition& AttributeCaptureDefinition, const FAggregatorEvaluateParameters& EvaluateParameters) const
{
	float AttributeMagnitude;

	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(AttributeCaptureDefinition, EvaluateParameters, AttributeMagnitude);

	return AttributeMagnitude;
}

void UAuraDamageExecution::CalculateBlockChance(float BlockChanceMagnitude, float& OutDamage) const
{
	//Successful Block. Maybe sending a Gameplay Event here to the target actor could help display damage texts?
	if (BlockChanceMagnitude != 0.0f && FMath::RandRange(1.0f, 100.0f) < BlockChanceMagnitude)
	{
		OutDamage *= 0.5f;
	}
}

void UAuraDamageExecution::CalculateArmorPenetration(float TargetAmor, float SourceArmorPenetration, float& OutDamage) const
{
	float EffectiveArmor = TargetAmor;

	EffectiveArmor *= (100 - SourceArmorPenetration) / 100;

	OutDamage *= (100 - EffectiveArmor) / 100;

	OutDamage = FMath::Clamp(OutDamage, 0.0f, UE_BIG_NUMBER);
}

void UAuraDamageExecution::CalculateCriticalHit(float SourceCriticalHitChance, float TargetCriticalHitResistance, float CriticalHitDamage, float& OutDamage) const
{
	SourceCriticalHitChance *= (100 - TargetCriticalHitResistance) / 100;

	SourceCriticalHitChance = FMath::Clamp(OutDamage, 0.0f, UE_BIG_NUMBER);

	if (SourceCriticalHitChance != 0.0f && FMath::RandRange(1.0f, 100.0f) < SourceCriticalHitChance)
	{
		OutDamage *= 2.0f;

		OutDamage += CriticalHitDamage;
	}
}
