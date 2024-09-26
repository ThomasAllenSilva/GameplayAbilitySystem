// Thomas Learning Project

#include "Characters/Base/AuraCharacterBase.h"

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
}

// Called when the game starts or when spawned
void AAuraCharacterBase::BeginPlay()
{
	Super::BeginPlay();
}

