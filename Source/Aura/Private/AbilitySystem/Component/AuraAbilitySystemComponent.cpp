// Thomas Learning Project


#include "AbilitySystem/Component/AuraAbilitySystemComponent.h"

#include "GameplayEffect.h"

UAuraAbilitySystemComponent::UAuraAbilitySystemComponent()
{

}

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
}
