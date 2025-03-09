// Thomas Learning Project

#include "Characters/Base/AuraCharacterBase.h"
#include "Components/CommonAbilitySystemComponent.h"
#include "MotionWarpingComponent.h"

AAuraCharacterBase::AAuraCharacterBase()
{
	PrimaryActorTick.bCanEverTick = true;

	PrimaryActorTick.bStartWithTickEnabled = false;

	PrimaryActorTick.bAllowTickOnDedicatedServer = false;

	WeaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");

	WeaponMesh->SetupAttachment(GetMesh(), "WeaponHandSocket");

	WeaponMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	WeaponMesh->PrimaryComponentTick.bCanEverTick = true;

	WeaponMesh->PrimaryComponentTick.bStartWithTickEnabled = false;

	WeaponMesh->PrimaryComponentTick.bAllowTickOnDedicatedServer = false;

	MotionWarpingComponent = CreateDefaultSubobject<UMotionWarpingComponent>("Motion Warping");
}

UAbilitySystemComponent* AAuraCharacterBase::GetAbilitySystemComponent() const
{
	check(nullptr);

	return nullptr;
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
	return GetAbilitySystemComponent()->HasAnyMatchingGameplayTags(TagContainer);
}

bool AAuraCharacterBase::HasAllMatchingGameplayTags(const FGameplayTagContainer& TagContainer) const
{
	return GetAbilitySystemComponent()->HasAllMatchingGameplayTags(TagContainer);
}


FVector AAuraCharacterBase::GetWeaponSocketLocation() const
{
	return WeaponMesh->GetSocketLocation(WeaponSocketName);
}

void AAuraCharacterBase::UpdateWarpTargetFromLocation(const FVector& Location)
{
	MotionWarpingComponent->AddOrUpdateWarpTargetFromLocation(WarpName, Location);
}

void AAuraCharacterBase::SetTargetActor(AActor* InTargetActor)
{
	check(InTargetActor);

	TargetActor = InTargetActor;
}

AActor* AAuraCharacterBase::GetTargetActor() const
{
	return TargetActor.Get();
}

AActor* AAuraCharacterBase::GetTargetActorChecked() const
{
	check(TargetActor.IsValid());

	return TargetActor.Get();
}

FVector AAuraCharacterBase::GetTargetActorLocation() const
{
	if (AActor* Actor = TargetActor.Get())
	{
		return Actor->GetActorLocation();
	}

	return FVector::ZeroVector;
}

void AAuraCharacterBase::ClearTargetActor()
{
	TargetActor.Reset();
}
