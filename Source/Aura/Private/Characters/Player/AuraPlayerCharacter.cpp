// Thomas Learning Project


#include "Characters/Player/AuraPlayerCharacter.h"

#include "Player/State/AuraPlayerState.h"

void AAuraPlayerCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	AAuraPlayerState* AuraPlayerState = GetPlayerState<AAuraPlayerState>();

	AbilitySystemComponent = AuraPlayerState->GetAbilitySystemComponent();

	check(AbilitySystemComponent);
}
