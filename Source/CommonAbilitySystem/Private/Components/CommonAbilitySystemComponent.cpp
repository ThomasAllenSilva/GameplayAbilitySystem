// Thomas Learning Project

#include "Components/CommonAbilitySystemComponent.h"
#include "Data/DataAsset_CommonAbilitySet.h"

void UCommonAbilitySystemComponent::AbilityInputTriggered(const FGameplayTag& InputTag)
{
	for (FGameplayAbilitySpec& AbilitySpec : GetActivatableAbilities())
	{
		if (AbilitySpec.DynamicAbilityTags.HasTagExact(InputTag))
		{
			AbilitySpecInputPressed(AbilitySpec);

			if (AbilitySpec.IsActive() == false)
			{
				TryActivateAbility(AbilitySpec.Handle);
			}
		}
	}
}

void UCommonAbilitySystemComponent::AbilityInputReleased(const FGameplayTag& InputTag)
{
	for (FGameplayAbilitySpec& AbilitySpec : GetActivatableAbilities())
	{
		if (AbilitySpec.DynamicAbilityTags.HasTagExact(InputTag))
		{
			AbilitySpecInputReleased(AbilitySpec);
		}
	}
}

void UCommonAbilitySystemComponent::InitializeAbilitySets()
{
	//we first grant the attribute sets in case we want to apply GEs that needs them
	for (int32 SetIndex = 0; SetIndex < AbilitySets.Num(); ++SetIndex)
	{
		UDataAsset_CommonAbilitySet* AbilitySet = AbilitySets[SetIndex];

		AbilitySet->GiveAttributeSetsToAbilitySystem(this);
	}

	for (int32 SetIndex = 0; SetIndex < AbilitySets.Num(); ++SetIndex)
	{
		UDataAsset_CommonAbilitySet* AbilitySet = AbilitySets[SetIndex];

		AbilitySet->GiveToAbilitySystem(this);
	}

	OnInitializedAbilitySets.Broadcast();
}

const FGameplayTag& UCommonAbilitySystemComponent::GetTagID() const
{
	return TagID;
}
