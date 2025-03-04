// Thomas Learning Project

#include "AbilitySystem/Ability/AuraProjectileSpell.h"
#include "AbilitySystem/Actor/AuraProjectile.h"

void UAuraProjectileSpell::SpawnProjectile(const FVector& TargetLocation)
{
	AAuraProjectile::CreateProjectile(this, ProjectileClass, GetAvatarActorFromActorInfo(), TargetLocation, GetAbilityEffectsSpecs());
}
