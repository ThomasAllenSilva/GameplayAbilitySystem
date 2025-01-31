// Thomas Learning Project


#include "Characters/Player/AuraPlayerCharacter.h"

#include "Components/CommonAbilitySystemComponent.h"

#include "PlayerState/CommonAbilityPlayerState.h"

void AAuraPlayerCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	ACommonAbilityPlayerState* CommonAbilityPlayerState = GetPlayerState<ACommonAbilityPlayerState>();

	AbilitySystemComponent = Cast<UCommonAbilitySystemComponent>(CommonAbilityPlayerState->GetAbilitySystemComponent());

	check(AbilitySystemComponent);
}
