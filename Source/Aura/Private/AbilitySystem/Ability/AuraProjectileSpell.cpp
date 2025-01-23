// Thomas Learning Project

#include "AbilitySystem/Ability/AuraProjectileSpell.h"

#include "AbilitySystem/Actor/AuraProjectile.h"

#include "AbilitySystemComponent.h"

#include "AbilitySystemBlueprintLibrary.h"

#include "AuraNativeGameplayTags.h"

void UAuraProjectileSpell::SpawnProjectile(const FVector& TargetLocation)
{
	UAbilitySystemComponent* ASC = GetAbilitySystemComponentFromActorInfo();

	TArray<FGameplayEffectSpecHandle> EffectSpecHandles;

	for (TSubclassOf<UGameplayEffect>& GameplayEffect : SpellEffects)
	{
		FGameplayEffectSpecHandle EffectSpecHandle = ASC->MakeOutgoingSpec(GameplayEffect, GetAbilityLevel(), ASC->MakeEffectContext());

		EffectSpecHandle = UAbilitySystemBlueprintLibrary::AssignTagSetByCallerMagnitude(EffectSpecHandle, Damage, ScalableDamage.GetValueAtLevel(GetAbilityLevel()));

		EffectSpecHandles.Add(EffectSpecHandle);
	}

	AAuraProjectile::CreateProjectile(this, ProjectileClass, GetAvatarActorFromActorInfo(), TargetLocation, EffectSpecHandles);
}
