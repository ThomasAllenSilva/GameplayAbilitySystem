// Thomas Hero Project

#include "PlayerController/CommonAbilityPlayerController.h"
#include "Input/CommonAbilityInputComponent.h"
#include "CommonAbilityFunctionLibrary.h"
#include "EnhancedInputSubsystems.h"
#include "Components/CommonAbilitySystemComponent.h"

void ACommonAbilityPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	checkf(InputConfig, TEXT("Null Or Invalid InputConfig When Setting Up Input"));

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());

	Subsystem->AddMappingContext(InputConfig->GetInputMappingContext(), InputConfig->GetMappingContextPriority());

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
