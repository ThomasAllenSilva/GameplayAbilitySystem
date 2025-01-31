// Thomas Hero Project


#include "PlayerController/CommonAbilityPlayerController.h"
#include "Input/CommonAbilityInputComponent.h"
#include "CommonAbilityFunctionLibrary.h"
#include "Components/CommonAbilitySystemComponent.h"

void ACommonAbilityPlayerController::SetupInputComponent()
{
	UCommonAbilityInputComponent* AbilityInputComponent = CastChecked<UCommonAbilityInputComponent>(InputComponent);

	AbilityInputComponent->BindAbilityActions(InputConfig, this, &ACommonAbilityPlayerController::AbilityInputTriggered, &ACommonAbilityPlayerController::AbilityInputReleased);
}

void ACommonAbilityPlayerController::AbilityInputTriggered(FGameplayTag InputTag)
{
	UCommonAbilityFunctionLibrary::GetLocalPlayerAbilitySystemComponent(this)->AbilityInputTriggered(InputTag);
}

void ACommonAbilityPlayerController::AbilityInputReleased(FGameplayTag InputTag)
{
	UCommonAbilityFunctionLibrary::GetLocalPlayerAbilitySystemComponent(this)->AbilityInputReleased(InputTag);
}
