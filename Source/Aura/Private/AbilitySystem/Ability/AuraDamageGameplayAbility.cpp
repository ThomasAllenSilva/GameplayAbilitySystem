// Thomas Learning Project

#include "AuraDamageGameplayAbility.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystemComponent.h"

void UAuraDamageGameplayAbility::ApplyDamage(AActor* TargetActor)
{
	UAbilitySystemComponent* TargetASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(TargetActor);

	if (TargetASC != nullptr)
	{
		for (const FGameplayEffectSpecHandle& EffectSpec : GetAbilityEffectsSpecs())
		{
			TargetASC->ApplyGameplayEffectSpecToSelf(*EffectSpec.Data.Get());
		}
	}
}

TArray<FGameplayEffectSpecHandle> UAuraDamageGameplayAbility::GetAbilityEffectsSpecs()
{
	check(DamageEffect);

	TArray<FGameplayEffectSpecHandle> EffectSpecHandles;

	FGameplayEffectSpecHandle DamageEffectSpecHandle = MakeOutgoingGameplayEffectSpec(DamageEffect, GetAbilityLevel());

	for (const TPair<const FGameplayTag, FScalableFloat>& Pair : DamageTypes)
	{
		float TypeDamageMagnitude = Pair.Value.GetValueAtLevel(GetAbilityLevel());

		DamageEffectSpecHandle.Data.Get()->SetSetByCallerMagnitude(Pair.Key, TypeDamageMagnitude);
	}

	EffectSpecHandles.Add(DamageEffectSpecHandle);

	for (const TSubclassOf<UGameplayEffect>& GameplayEffect : OtherEffects)
	{
		FGameplayEffectSpecHandle EffectSpecHandle = MakeOutgoingGameplayEffectSpec(GameplayEffect, GetAbilityLevel());

		EffectSpecHandles.Add(EffectSpecHandle);
	}

	return EffectSpecHandles;
}
