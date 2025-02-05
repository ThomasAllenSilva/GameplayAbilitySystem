// Thomas Learning Project


#include "AuraVitalAttributeSet.h"
#include "GameplayEffectExtension.h"
#include "CommonAbilityFunctionLibrary.h"
#include "AuraNativeGameplayTags.h"

void UAuraVitalAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	NewValue = FMath::Clamp(NewValue, 0.0f, 100.0f);
}

void UAuraVitalAttributeSet::PreAttributeBaseChange(const FGameplayAttribute& Attribute, float& NewValue) const
{
	NewValue = FMath::Clamp(NewValue, 0.0f, 100.0f);
}

void UAuraVitalAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	if (Data.EvaluatedData.Attribute == GetHealthAttribute())
	{
		if (GetHealth() <= 0.0f)
		{
			UCommonAbilityFunctionLibrary::AddGameplayTagToActorIfNone(Data.Target.GetAvatarActor(), Common_Status_Dead);
		}
	}
}
