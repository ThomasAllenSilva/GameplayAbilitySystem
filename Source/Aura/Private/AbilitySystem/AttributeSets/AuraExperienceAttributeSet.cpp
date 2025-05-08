// Thomas Learning Project

#include "AbilitySystem/AttributeSets/AuraExperienceAttributeSet.h"
#include "GameplayEffectExtension.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "GameplayEffectTypes.h"
#include "AbilitySystem/Interfaces/AuraExperienceInterface.h"
#include "AuraNativeGameplayTags.h"

void UAuraExperienceAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	if (Data.EvaluatedData.Attribute == GetIncomingXPAttribute())
	{
		const IAuraExperienceInterface* AuraExperienceInterface = CastChecked<IAuraExperienceInterface>(GetOwningActor());

		const float GainedXP = GetIncomingXP();

		const float NewTotalXP = GetXP() + GainedXP;

		const int NewLevel = AuraExperienceInterface->GetLevelForXP(NewTotalXP);

		const int AmountOfLevelsUp = NewLevel - GetLevel();

		for (int i = 0; i < AmountOfLevelsUp; i++)
		{
			const int CurrentLevel = GetLevel();

			UAbilitySystemBlueprintLibrary::SendGameplayEventToActor(GetOwningActor(), CharacterEvents_LeveledUp, FGameplayEventData());

			SetLevel(CurrentLevel + 1);
		}

		SetXP(NewTotalXP);

		SetIncomingXP(0.0f);
	}
}
