// Thomas Hero Project

#include "PlayerState/CommonAbilityPlayerState.h"

#include "Components/CommonAbilitySystemComponent.h"

ACommonAbilityPlayerState::ACommonAbilityPlayerState()
{
	AbilitySystemComponent = CreateDefaultSubobject<UCommonAbilitySystemComponent>("AbilitySystemComponent");
}

void ACommonAbilityPlayerState::BeginPlay()
{
	AbilitySystemComponent->InitAbilityActorInfo(this, GetPawn());

	AbilitySystemComponent->InitializeAbilitySets();

	Super::BeginPlay();
}

UAbilitySystemComponent* ACommonAbilityPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
