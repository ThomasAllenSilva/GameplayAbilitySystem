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

void UCommonAbilitySystemComponent::BeginPlay()
{
	Super::BeginPlay();

	for (int32 SetIndex = 0; SetIndex < AbilitySets.Num(); ++SetIndex)
	{
		UDataAsset_CommonAbilitySet* AbilitySet = AbilitySets[SetIndex];

		AbilitySet->GiveToAbilitySystem(this);
	}

	bIsInitialized = true;

	OnInitialized.Broadcast();
}
