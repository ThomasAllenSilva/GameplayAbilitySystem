// Thomas Learning Project


#include "AuraPlayerController.h"
#include "InputActionValue.h"
#include "GameFramework/Character.h"
#include "AuraNativeGameplayTags.h"
#include "Input/CommonAbilityInputComponent.h"

void AAuraPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UCommonAbilityInputComponent* AbilityInputComponent = CastChecked<UCommonAbilityInputComponent>(InputComponent);

	AbilityInputComponent->BindNativeInput(InputConfig, Input_Move, ETriggerEvent::Triggered, this, &AAuraPlayerController::Move);

	bEnableMouseOverEvents = true;

	bShowMouseCursor = true;
}

void AAuraPlayerController::Move(const FInputActionValue& InputValue)
{
	ACharacter* PlayerCharacter = GetCharacter();

	check(PlayerCharacter);

	const FVector2D Value = InputValue.Get<FVector2D>();

	const FVector ForwardInput = FVector::ForwardVector * Value.X;

	PlayerCharacter->AddMovementInput(ForwardInput);

	const FVector SidesInput = FVector::RightVector * Value.Y;

	PlayerCharacter->AddMovementInput(SidesInput);
}
