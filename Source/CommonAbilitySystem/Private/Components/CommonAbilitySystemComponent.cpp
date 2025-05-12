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

float UCommonAbilitySystemComponent::GetGameplayAttributeValueChecked(FGameplayAttribute Attribute)
{
	bool bFound = false;

	// validate the attribute
	if (Attribute.IsValid())
	{
		// get the associated AttributeSet
		const UAttributeSet* InternalAttributeSet = GetAttributeSubobject(Attribute.GetAttributeSetClass());

		if (InternalAttributeSet)
		{
			// NOTE: this is currently not taking predicted gameplay effect modifiers into consideration, so the value may not be accurate on client
			bFound = true;
			return Attribute.GetNumericValue(InternalAttributeSet);
		}
	}

	checkf(bFound, TEXT("Could not find attribute value associated with the attribute: %s"), *Attribute.GetName());

	return 0.0f;
}

const FGameplayTag& UCommonAbilitySystemComponent::GetTagID() const
{
	return TagID;
}
