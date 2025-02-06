// Thomas Learning Project

#include "Characters/Base/AuraCharacterBase.h"

#include "Components/CommonAbilitySystemComponent.h"

#include "MotionWarpingComponent.h"

AAuraCharacterBase::AAuraCharacterBase()
{
	PrimaryActorTick.bCanEverTick = false;

	PrimaryActorTick.bStartWithTickEnabled = false;

	PrimaryActorTick.bAllowTickOnDedicatedServer = false;

	WeaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");

	WeaponMesh->SetupAttachment(GetMesh(), "WeaponHandSocket");

	WeaponMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	WeaponMesh->PrimaryComponentTick.bCanEverTick = false;

	WeaponMesh->PrimaryComponentTick.bStartWithTickEnabled = false;

	WeaponMesh->PrimaryComponentTick.bAllowTickOnDedicatedServer = false;

	MotionWarpingComponent = CreateDefaultSubobject<UMotionWarpingComponent>("Motion Warping");
}

UAbilitySystemComponent* AAuraCharacterBase::GetAbilitySystemComponent() const
{
	check(nullptr);

	return nullptr;
}

FVector AAuraCharacterBase::GetProjectileSpawnLocation()
{
	return WeaponMesh->GetSocketLocation(ProjectileSocketName);
}

void AAuraCharacterBase::UpdateWarpTargetFromLocation(const FVector& Location)
{
	MotionWarpingComponent->AddOrUpdateWarpTargetFromLocation(WarpName, Location);
}
