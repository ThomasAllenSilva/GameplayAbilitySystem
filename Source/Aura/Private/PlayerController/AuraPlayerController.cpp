// Thomas Learning Project


#include "PlayerController/AuraPlayerController.h"

#include "EnhancedInputSubsystems.h"

#include "InputMappingContext.h"

#include "InputAction.h"

#include "InputActionValue.h"

#include "GameFramework/Character.h"

#include "Input/AuraEnhancedInputComponent.h"

#include "Debug.h"
#include "AuraBlueprintFunctionLibrary.h"
#include "AbilitySystem/Component/AuraAbilitySystemComponent.h"
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

	ASSERT_CONDITION(InputConfig != nullptr, TEXT("Input Config Is Null. Not Possible To Continue Input Binding"))

	bShowMouseCursor = true;

	bEnableMouseOverEvents = true;

	UAuraEnhancedInputComponent* EnhancedInput = CastChecked<UAuraEnhancedInputComponent>(InputComponent);

	EnhancedInput->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AAuraPlayerController::Move);

	EnhancedInput->BindAbilityInput(InputConfig, this, &AAuraPlayerController::AbilityInputHeld, ETriggerEvent::Triggered);

	EnhancedInput->BindAbilityInput(InputConfig, this, &AAuraPlayerController::AbilityInputReleased, ETriggerEvent::Canceled);
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

void AAuraPlayerController::AbilityInputHeld(FGameplayTag InputTag)
{
	UAuraBlueprintFunctionLibrary::GetLocalPlayerAbilitySystemComponent(this)->AbilityInputHeld(InputTag);
}

void AAuraPlayerController::AbilityInputReleased(FGameplayTag InputTag)
{
	UAuraBlueprintFunctionLibrary::GetLocalPlayerAbilitySystemComponent(this)->AbilityInputReleased(InputTag);
}
