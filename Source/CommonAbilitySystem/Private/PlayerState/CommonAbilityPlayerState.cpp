// Thomas Hero Project

#include "PlayerState/CommonAbilityPlayerState.h"

#include "Components/CommonAbilitySystemComponent.h"

ACommonAbilityPlayerState::ACommonAbilityPlayerState()
{
	AbilitySystemComponent = CreateDefaultSubobject<UCommonAbilitySystemComponent>("AbilitySystemComponent");
}

void ACommonAbilityPlayerState::BeginPlay()
{
	Super::BeginPlay();

	AbilitySystemComponent->InitAbilityActorInfo(this, GetPawn());

	AbilitySystemComponent->InitializeAbilitySets();
}

UAbilitySystemComponent* ACommonAbilityPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
