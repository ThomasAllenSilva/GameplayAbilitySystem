// Thomas Learning Project

#include "AbilitySystem/Component/AuraAbilitySystemComponent.h"

#include "AbilitySystem/Ability/AuraGameplayAbility.h"

#include "AbilitySystem/Data/CharacterClassSettings.h"

void UAuraAbilitySystemComponent::BeginPlay()
{
	Super::BeginPlay();

	if (CharacterClassConfiguration == nullptr)
	{
		return;
	}

	InitializeComponentConfiguration(CharacterClassConfiguration);
}

void UAuraAbilitySystemComponent::InitializeComponentConfiguration(const UCharacterClassSettings* ClassSettings)
{
	for (const TSubclassOf<UAttributeSet>& StartupAttribute : ClassSettings->GetStartupAttributes())
	{
		const UAttributeSet* AttributeSet = GetOrCreateAttributeSubobject(StartupAttribute);

		check(AttributeSet);
	}

	for (const TSubclassOf<UGameplayAbility>& StartupAbility : ClassSettings->GetStartupAbilities())
	{
		FGameplayAbilitySpec AbilitySpec = FGameplayAbilitySpec(StartupAbility);

		if (const UAuraGameplayAbility* AuraGameplayAbility = Cast<UAuraGameplayAbility>(AbilitySpec.Ability))
		{
			AbilitySpec.DynamicAbilityTags.AddTag(AuraGameplayAbility->InputTag);
		}

		GiveAbility(AbilitySpec);
	}

	for (const TSubclassOf<UGameplayEffect>& StartupEffect : ClassSettings->GetStartupEffects())
	{
		FGameplayEffectSpecHandle SpecHandle = MakeOutgoingSpec(StartupEffect, 1, MakeEffectContext());

		ApplyGameplayEffectSpecToSelf(*SpecHandle.Data.Get());
	}

	for (const TObjectPtr<UCharacterClassSettings>& SharedConfiguration : ClassSettings->GetSharedConfigurations())
	{
		InitializeComponentConfiguration(SharedConfiguration);
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
