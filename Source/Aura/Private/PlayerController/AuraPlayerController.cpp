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
}

void AAuraPlayerController::Move(const FInputActionValue& InputValue)
{
	if (GetCharacter() == nullptr)
	{
		return;
	}

	const FVector2D Value = InputValue.Get<FVector2D>();

	const FVector ForwardInput = FVector::ForwardVector * Value.X;

	GetCharacter()->AddMovementInput(ForwardInput);

	const FVector SidesInput = FVector::RightVector * Value.Y;

	GetCharacter()->AddMovementInput(SidesInput);
}
