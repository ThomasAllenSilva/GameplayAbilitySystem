// Thomas Learning Project


#include "AbilitySystem/Ability/AuraProjectileSpell.h"

#include "AbilitySystem/Actor/AuraProjectile.h"

#include "AbilitySystemComponent.h"

#include "AbilitySystemBlueprintLibrary.h"

#include "AuraNativeGameplayTags.h"

void UAuraProjectileSpell::SpawnProjectile(const FVector& TargetLocation)
{
	checkf(SpellEffect, TEXT("Invalid Or Null Effect When Creating Projectile"));

	UAbilitySystemComponent* ASC = GetAbilitySystemComponentFromActorInfo();

	FGameplayEffectSpecHandle EffectSpecHandle = ASC->MakeOutgoingSpec(SpellEffect, GetAbilityLevel(), ASC->MakeEffectContext());

	EffectSpecHandle = UAbilitySystemBlueprintLibrary::AssignTagSetByCallerMagnitude(EffectSpecHandle, Damage, ScalableDamage.GetValueAtLevel(GetAbilityLevel()));

	AAuraProjectile::CreateProjectile(this, ProjectileClass, GetAvatarActorFromActorInfo(), TargetLocation, EffectSpecHandle);
}
