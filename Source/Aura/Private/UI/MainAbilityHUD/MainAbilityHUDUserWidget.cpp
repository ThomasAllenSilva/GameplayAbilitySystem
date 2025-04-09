// Thomas Learning Project


#include "UI/MainAbilityHUD/MainAbilityHUDUserWidget.h"
#include "AbilitySystem/Data/DataAsset_AbilityInfo.h"
#include "CommonAbilityFunctionLibrary.h"
#include "Components/CommonAbilitySystemComponent.h"
#include "AuraNativeGameplayTags.h"

void UMainAbilityHUDUserWidget::NativeConstruct()
{
	Super::NativeConstruct();

	UCommonAbilitySystemComponent* PlayerASC = UCommonAbilityFunctionLibrary::GetLocalPlayerAbilitySystemComponent(this);

	TArray<FGameplayAbilitySpec>& ActivatableAbilities = PlayerASC->GetActivatableAbilities();

	for (const FGameplayAbilitySpec& Ability : ActivatableAbilities)
	{
		if (Ability.DynamicAbilityTags.HasTag(Input))
		{
			const TArray<FGameplayTag>& Tags = Ability.DynamicAbilityTags.GetGameplayTagArray();

			for (const FGameplayTag& Tag : Tags)
			{
				if (Tag.MatchesTag(Input))
				{
					const FGameplayTag& AbilityMainTag = Ability.Ability->AbilityTags.First();

					checkf(AbilityMainTag.IsValid(), TEXT("The Ability Has An Invalid Main Tag: %s"), *Ability.Ability.GetFName().ToString())

					OnUpdateAbility(AbilityMainTag, Tag);
				}
			}
		}
	}
}

FAuraAbilityInfo UMainAbilityHUDUserWidget::GetAbilityInfoForAbilityTag(const FGameplayTag& AbilityTag) const
{
	return AbilitiesInfo->GetAbilityInfoByTag(AbilityTag);
}
