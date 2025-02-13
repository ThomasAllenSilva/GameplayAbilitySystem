// Thomas Learning Project

#include "AbilitySystem/Ability/AuraProjectileSpell.h"
#include "AbilitySystem/Actor/AuraProjectile.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystemBlueprintLibrary.h"

void UAuraProjectileSpell::SpawnProjectile(const FVector& TargetLocation)
{
	UAbilitySystemComponent* ASC = GetAbilitySystemComponentFromActorInfo();

	TArray<FGameplayEffectSpecHandle> EffectSpecHandles;

	for (const TSubclassOf<UGameplayEffect>& GameplayEffect : DamageEffects)
	{
		FGameplayEffectSpecHandle EffectSpecHandle = ASC->MakeOutgoingSpec(GameplayEffect, GetAbilityLevel(), ASC->MakeEffectContext());

		for (const TPair<const FGameplayTag, FScalableFloat>& Pair : DamageTypes)
		{
			EffectSpecHandle = UAbilitySystemBlueprintLibrary::AssignTagSetByCallerMagnitude(EffectSpecHandle, Pair.Key, Pair.Value.GetValueAtLevel(GetAbilityLevel()));
		}

		EffectSpecHandles.Add(EffectSpecHandle);
	}

	for (const TSubclassOf<UGameplayEffect>& GameplayEffect : OtherEffects)
	{
		FGameplayEffectSpecHandle EffectSpecHandle = ASC->MakeOutgoingSpec(GameplayEffect, GetAbilityLevel(), ASC->MakeEffectContext());

		EffectSpecHandles.Add(EffectSpecHandle);
	}

	AAuraProjectile::CreateProjectile(this, ProjectileClass, GetAvatarActorFromActorInfo(), TargetLocation, EffectSpecHandles);
}
