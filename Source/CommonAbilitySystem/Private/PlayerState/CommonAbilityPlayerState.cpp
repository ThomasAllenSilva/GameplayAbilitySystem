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

	check(GetPawn());

	AbilitySystemComponent->InitAbilityActorInfo(this, GetPawn());
}

UAbilitySystemComponent* ACommonAbilityPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
