// Thomas Learning Project

#include "Characters/Base/AuraCharacterBase.h"
#include "Components/CommonAbilitySystemComponent.h"
#include "MotionWarpingComponent.h"

#include "Debug.h"

AAuraCharacterBase::AAuraCharacterBase()
{
	PrimaryActorTick.bCanEverTick = true;

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

void AAuraCharacterBase::GetOwnedGameplayTags(FGameplayTagContainer& TagContainer) const
{
	return GetAbilitySystemComponent()->GetOwnedGameplayTags(TagContainer);
}

bool AAuraCharacterBase::HasMatchingGameplayTag(FGameplayTag TagToCheck) const
{
	return GetAbilitySystemComponent()->HasMatchingGameplayTag(TagToCheck);
}

bool AAuraCharacterBase::HasAnyMatchingGameplayTags(const FGameplayTagContainer& TagContainer) const
{
	if (GetAbilitySystemComponent()->HasAnyMatchingGameplayTags(TagContainer))
	{
		UE_LOG(LogTemp, Display, TEXT("Has Gameplay Tag"));
	}
	else
	{
		UE_LOG(LogTemp, Display, TEXT("Don't Have Gameplay Tag"));
	}
	return GetAbilitySystemComponent()->HasAnyMatchingGameplayTags(TagContainer);
}

bool AAuraCharacterBase::HasAllMatchingGameplayTags(const FGameplayTagContainer& TagContainer) const
{
	return GetAbilitySystemComponent()->HasAllMatchingGameplayTags(TagContainer);
}
