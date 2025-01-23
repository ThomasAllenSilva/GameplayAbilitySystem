// Thomas Learning Project

#include "AbilitySystem/Component/AuraAbilitySystemComponent.h"

#include "AuraBlueprintFunctionLibrary.h"

#include "AbilitySystem/Ability/AuraGameplayAbility.h"

#include "AbilitySystem/Data/CharacterClassSettings.h"

void UAuraAbilitySystemComponent::BeginPlay()
{
	Super::BeginPlay();

	UAuraBlueprintFunctionLibrary::InitializeGlobalCharacterClass(this, CharacterClassTag, this);

	if (CharacterClassConfiguration == nullptr)
	{
		return;
	}

	for (const TSubclassOf<UGameplayAbility>& StartupAbility : CharacterClassConfiguration->GetStartupAbilities())
	{
		FGameplayAbilitySpec AbilitySpec = FGameplayAbilitySpec(StartupAbility);

		if (const UAuraGameplayAbility* AuraGameplayAbility = Cast<UAuraGameplayAbility>(AbilitySpec.Ability))
		{
			AbilitySpec.DynamicAbilityTags.AddTag(AuraGameplayAbility->InputTag);
		}

		GiveAbility(AbilitySpec);
	}

	for (const TSubclassOf<UGameplayEffect>& StartupEffect : CharacterClassConfiguration->GetStartupEffects())
	{
		FGameplayEffectSpecHandle SpecHandle = MakeOutgoingSpec(StartupEffect, 1, MakeEffectContext());

		ApplyGameplayEffectSpecToSelf(*SpecHandle.Data.Get());
	}
}

void UAuraAbilitySystemComponent::AbilityInputHeld(const FGameplayTag& InputTag)
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

void UAuraAbilitySystemComponent::AbilityInputReleased(const FGameplayTag& InputTag)
{
	for (FGameplayAbilitySpec& AbilitySpec : GetActivatableAbilities())
	{
		if (AbilitySpec.DynamicAbilityTags.HasTagExact(InputTag))
		{
			AbilitySpecInputReleased(AbilitySpec);
		}
	}
}
