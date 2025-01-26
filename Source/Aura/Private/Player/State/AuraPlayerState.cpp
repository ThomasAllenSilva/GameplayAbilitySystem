// Thomas Learning Project

#include "Player/State/AuraPlayerState.h"

#include "AbilitySystem/Component/AuraAbilitySystemComponent.h"

AAuraPlayerState::AAuraPlayerState()
{
	AbilitySystemComponent = CreateDefaultSubobject<UAuraAbilitySystemComponent>("AbilitySystemComponent");
}

UAbilitySystemComponent* AAuraPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void AAuraPlayerState::BeginPlay()
{
	Super::BeginPlay();

	checkf(GetPawn(), TEXT("NULL Pawn When Initing Ability Actor Info"));

	AbilitySystemComponent->InitAbilityActorInfo(this, GetPawn());
}
