// Thomas Learning Project


#include "AbilitySystem/Component/AuraAbilitySystemComponent.h"

#include "GameplayEffect.h"

#include "AbilitySystem/Ability/AuraGameplayAbility.h"

void UAuraAbilitySystemComponent::BeginPlay()
{
	Super::BeginPlay();

	for (TSubclassOf<UGameplayEffect>& EffectTemplate : InitializationEffects)
	{
		if (IsValid(EffectTemplate) == false)
		{
			continue;
		}

		const FGameplayEffectContextHandle ContextHandle = MakeEffectContext();

		const FGameplayEffectSpecHandle SpecHandle = MakeOutgoingSpec(EffectTemplate, 1.0f, ContextHandle);

		ApplyGameplayEffectSpecToSelf(*SpecHandle.Data.Get());
	}

	for (TSubclassOf<UGameplayAbility>& AbilityTemplate : InitialAbilities)
	{
		FGameplayAbilitySpec AbilitySpec = FGameplayAbilitySpec(AbilityTemplate);

		if (const UAuraGameplayAbility* AuraGameplayAbility = Cast<UAuraGameplayAbility>(AbilitySpec.Ability))
		{
			AbilitySpec.DynamicAbilityTags.AddTag(AuraGameplayAbility->InputTag);
		}

		GiveAbility(AbilitySpec);
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
