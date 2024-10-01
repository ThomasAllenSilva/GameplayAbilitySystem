// Thomas Learning Project


#include "PlayerController/AuraPlayerController.h"

#include "EnhancedInputSubsystems.h"

#include "EnhancedInputComponent.h"

#include "InputMappingContext.h"

#include "InputAction.h"

#include "InputActionValue.h"

#include "GameFramework/Character.h"

void AAuraPlayerController::BeginPlay()
{
	Super::BeginPlay();

	check(InputContext);

	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(InputContext, 0);
	}
}

void AAuraPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputComponent* EnhancedInput = CastChecked<UEnhancedInputComponent>(InputComponent);

	EnhancedInput->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AAuraPlayerController::Move);
}

void AAuraPlayerController::Move(const FInputActionValue& InputValue)
{
	const FVector2D Value = InputValue.Get<FVector2D>();

	const FVector ForwardInput = FVector::ForwardVector * Value.X;

	GetCharacter()->AddMovementInput(ForwardInput);

	const FVector SidesInput = FVector::RightVector * Value.Y;

	GetCharacter()->AddMovementInput(SidesInput);
}
