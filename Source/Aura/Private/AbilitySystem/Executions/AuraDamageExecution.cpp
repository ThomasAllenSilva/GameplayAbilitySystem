// Thomas Learning Project


#include "AuraDamageExecution.h"
#include "AbilitySystem/AttributeSets/AuraVitalAttributeSet.h"
#include "AbilitySystem/AttributeSets/AuraSecondaryAttributeSet.h"
#include "AbilitySystem/AttributeSets/AuraResistanceAttributeSet.h"
#include "AuraNativeGameplayTags.h"
#include "AbilitySystem/Types/AuraEffectTypes.h"
#include "GameplayTagsManager.h"

struct FDamageStatics
{
	DECLARE_ATTRIBUTE_CAPTUREDEF(Armor)

	DECLARE_ATTRIBUTE_CAPTUREDEF(ArmorPenetration)

	DECLARE_ATTRIBUTE_CAPTUREDEF(BlockChance)

	DECLARE_ATTRIBUTE_CAPTUREDEF(CriticalHitChance)

	DECLARE_ATTRIBUTE_CAPTUREDEF(CriticalHitResistance)

	DECLARE_ATTRIBUTE_CAPTUREDEF(CriticalHitDamage)

	DECLARE_ATTRIBUTE_CAPTUREDEF(FireResistance)

	DECLARE_ATTRIBUTE_CAPTUREDEF(LightningResistance)

	DECLARE_ATTRIBUTE_CAPTUREDEF(ArcaneResistance)

	DECLARE_ATTRIBUTE_CAPTUREDEF(PhysicalResistance)


	FDamageStatics()
	{
		//Secondary attributes
		DEFINE_ATTRIBUTE_CAPTUREDEF(UAuraSecondaryAttributeSet, Armor, Target, false);
		DEFINE_ATTRIBUTE_CAPTUREDEF(UAuraSecondaryAttributeSet, ArmorPenetration, Target, false);
		DEFINE_ATTRIBUTE_CAPTUREDEF(UAuraSecondaryAttributeSet, BlockChance, Target, false);
		DEFINE_ATTRIBUTE_CAPTUREDEF(UAuraSecondaryAttributeSet, CriticalHitChance, Source, false);
		DEFINE_ATTRIBUTE_CAPTUREDEF(UAuraSecondaryAttributeSet, CriticalHitResistance, Target, false);
		DEFINE_ATTRIBUTE_CAPTUREDEF(UAuraSecondaryAttributeSet, CriticalHitDamage, Source, false);

		//Resistance attributes
		DEFINE_ATTRIBUTE_CAPTUREDEF(UAuraResistanceAttributeSet, FireResistance, Target, false);
		DEFINE_ATTRIBUTE_CAPTUREDEF(UAuraResistanceAttributeSet, LightningResistance, Target, false);
		DEFINE_ATTRIBUTE_CAPTUREDEF(UAuraResistanceAttributeSet, ArcaneResistance, Target, false);
		DEFINE_ATTRIBUTE_CAPTUREDEF(UAuraResistanceAttributeSet, PhysicalResistance, Target, false);

		DamageTypeToResistanceAttributeDef.Add(Damage_Fire, FireResistanceDef);
		DamageTypeToResistanceAttributeDef.Add(Damage_Lightning, LightningResistanceDef);
		DamageTypeToResistanceAttributeDef.Add(Damage_Arcane, ArcaneResistanceDef);
		DamageTypeToResistanceAttributeDef.Add(Damage_Physical, PhysicalResistanceDef);
	}

public:
	const FGameplayEffectAttributeCaptureDefinition& GetResistanceAttributeDefByTag(const FGameplayTag& Tag) const { return DamageTypeToResistanceAttributeDef.FindChecked(Tag); }


private:
	TMap<FGameplayTag, FGameplayEffectAttributeCaptureDefinition> DamageTypeToResistanceAttributeDef;
};

static const FDamageStatics& DamageStatics()
{
	static FDamageStatics Statics;

	return Statics;
}

UAuraDamageExecution::UAuraDamageExecution()
{
	const FDamageStatics& DamageStatic = DamageStatics();

	//Secondary attributes
	RelevantAttributesToCapture.Add(DamageStatic.ArmorDef);
	RelevantAttributesToCapture.Add(DamageStatic.ArmorPenetrationDef);
	RelevantAttributesToCapture.Add(DamageStatic.BlockChanceDef);
	RelevantAttributesToCapture.Add(DamageStatic.CriticalHitChanceDef);
	RelevantAttributesToCapture.Add(DamageStatic.CriticalHitResistanceDef);
	RelevantAttributesToCapture.Add(DamageStatic.CriticalHitDamageDef);

	//Resistance attributes
	RelevantAttributesToCapture.Add(DamageStatic.FireResistanceDef);
	RelevantAttributesToCapture.Add(DamageStatic.LightningResistanceDef);
	RelevantAttributesToCapture.Add(DamageStatic.ArcaneResistanceDef);
	RelevantAttributesToCapture.Add(DamageStatic.PhysicalResistanceDef);
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

	FAuraGameplayEffectContext* EffectContext = static_cast<FAuraGameplayEffectContext*>(Spec.GetContext().Get());

	float TotalDamage = 0.0f;

	FGameplayTagContainer DamageTagContainer = UGameplayTagsManager::Get().RequestGameplayTagChildren(Damage);

	for (const FGameplayTag& DamageTypeTag : DamageTagContainer)
	{
		float TypeDamage = Spec.GetSetByCallerMagnitude(DamageTypeTag, false);

		if (TypeDamage == 0.0f)
		{
			continue;
		}

		const FGameplayEffectAttributeCaptureDefinition& ResistanceAttributeDefinition = DamageStatic.GetResistanceAttributeDefByTag(DamageTypeTag);

		float TypeResistance = 0.0f;

		ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(ResistanceAttributeDefinition, EvaluateParameters, TypeResistance);

		TypeDamage *= (100.0f - TypeResistance) / 100.0f;

		TotalDamage += TypeDamage;
	}

	float BlockChanceMagnitude = GetCalculatedCapturedAttributeMagnitude(ExecutionParams, DamageStatic.BlockChanceDef, EvaluateParameters);

	float TargetArmorMagnitude = GetCalculatedCapturedAttributeMagnitude(ExecutionParams, DamageStatic.ArmorDef, EvaluateParameters);

	float SourceArmorPenetrationMagnitude = GetCalculatedCapturedAttributeMagnitude(ExecutionParams, DamageStatic.ArmorPenetrationDef, EvaluateParameters);

	float SourceCriticalHitChance = GetCalculatedCapturedAttributeMagnitude(ExecutionParams, DamageStatic.CriticalHitChanceDef, EvaluateParameters);

	float TargetCriticalHitResistance = GetCalculatedCapturedAttributeMagnitude(ExecutionParams, DamageStatic.CriticalHitResistanceDef, EvaluateParameters);

	float SourceCriticalHitDamage = GetCalculatedCapturedAttributeMagnitude(ExecutionParams, DamageStatic.CriticalHitDamageDef, EvaluateParameters);

	CalculateBlockChance(BlockChanceMagnitude, TotalDamage, EffectContext);

	CalculateArmorPenetration(TargetArmorMagnitude, SourceArmorPenetrationMagnitude, TotalDamage);

	CalculateCriticalHit(SourceCriticalHitChance, TargetCriticalHitResistance, SourceCriticalHitDamage, TotalDamage, EffectContext);

	const FGameplayModifierEvaluatedData DamageModifierEvaluatedData(UAuraVitalAttributeSet::GetIncomingDamageAttribute(), EGameplayModOp::Additive, TotalDamage);

	OutExecutionOutput.AddOutputModifier(DamageModifierEvaluatedData);
}

float UAuraDamageExecution::GetCalculatedCapturedAttributeMagnitude(const FGameplayEffectCustomExecutionParameters& ExecutionParams, const FGameplayEffectAttributeCaptureDefinition& AttributeCaptureDefinition, const FAggregatorEvaluateParameters& EvaluateParameters) const
{
	float AttributeMagnitude;

	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(AttributeCaptureDefinition, EvaluateParameters, AttributeMagnitude);

	return AttributeMagnitude;
}

void UAuraDamageExecution::CalculateBlockChance(float BlockChanceMagnitude, float& OutDamage, FAuraGameplayEffectContext* EffectContext) const
{
	if (BlockChanceMagnitude != 0.0f && FMath::RandRange(1.0f, 100.0f) < BlockChanceMagnitude)
	{
		OutDamage *= 0.5f;

		EffectContext->SetIsBlockedHit(true);
	}
}

void UAuraDamageExecution::CalculateArmorPenetration(float TargetAmor, float SourceArmorPenetration, float& OutDamage) const
{
	float EffectiveArmor = TargetAmor;

	EffectiveArmor *= (100 - SourceArmorPenetration) / 100;

	OutDamage *= (100 - EffectiveArmor) / 100;

	OutDamage = FMath::Clamp(OutDamage, 0.0f, UE_BIG_NUMBER);
}

void UAuraDamageExecution::CalculateCriticalHit(float SourceCriticalHitChance, float TargetCriticalHitResistance, float CriticalHitDamage, float& OutDamage, FAuraGameplayEffectContext* EffectContext) const
{
	SourceCriticalHitChance *= (100 - TargetCriticalHitResistance) / 100;

	SourceCriticalHitChance = FMath::Clamp(OutDamage, 0.0f, UE_BIG_NUMBER);

	if (SourceCriticalHitChance != 0.0f && FMath::RandRange(1.0f, 100.0f) < SourceCriticalHitChance)
	{
		OutDamage *= 2.0f;

		OutDamage += CriticalHitDamage;

		EffectContext->SetIsCriticalHit(true);
	}
}
