// Thomas Learning Project


#include "Characters/Player/AuraPlayerCharacter.h"
#include "Components/CommonAbilitySystemComponent.h"
#include "Player/State/AuraPlayerState.h"


UAbilitySystemComponent* AAuraPlayerCharacter::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void AAuraPlayerCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	ACommonAbilityPlayerState* CommonAbilityPlayerState = GetPlayerState<ACommonAbilityPlayerState>();

	AbilitySystemComponent = Cast<UCommonAbilitySystemComponent>(CommonAbilityPlayerState->GetAbilitySystemComponent());

	check(AbilitySystemComponent);
}
