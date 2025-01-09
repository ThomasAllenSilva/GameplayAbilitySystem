// Thomas Learning Project


#include "AbilitySystem/Ability/AuraProjectileSpell.h"

#include "AbilitySystem/Actor/AuraProjectile.h"

#include "AbilitySystemComponent.h"

void UAuraProjectileSpell::SpawnProjectile(const FVector& TargetLocation)
{
	checkf(SpellEffect, TEXT("Invalid Or Null Effect When Creating Projectile"));

	UAbilitySystemComponent* ASC = GetAbilitySystemComponentFromActorInfo();

	FGameplayEffectSpecHandle EffectSpecHandle = ASC->MakeOutgoingSpec(SpellEffect, GetAbilityLevel(), ASC->MakeEffectContext());

	AAuraProjectile::CreateProjectile(this, ProjectileClass, GetAvatarActorFromActorInfo(), TargetLocation, EffectSpecHandle);
}
