// Thomas Learning Project

#include "AbilitySystem/AttributeSets/AuraExperienceAttributeSet.h"
#include "GameplayEffectExtension.h"
#include "GameplayEffectTypes.h"
#include "GameplayEffect.h"

void UAuraExperienceAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	//Data.EffectSpec.GetEffectContext().GetInstigatorAbilitySystemComponent(0)
	if (Data.EvaluatedData.Attribute == GetIncomingXPAttribute())
	{
		

		SetIncomingXP(0.0f);
	}
}
