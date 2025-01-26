// Thomas Learning Project

#pragma once

#include "CoreMinimal.h"

#include "GameFramework/PlayerController.h"

#include "GameplayTagContainer.h"

#include "AuraPlayerController.generated.h"

class UInputMappingContext;

class UInputAction;

struct FInputActionValue;

class UAuraInputConfigDataAsset;

UCLASS()
class AAuraPlayerController final : public APlayerController
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

	virtual void SetupInputComponent() override;

private:
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TObjectPtr<UInputMappingContext> InputContext;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TObjectPtr<UInputAction> MoveAction;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TObjectPtr<UAuraInputConfigDataAsset> InputConfig;

private:
	void Move(const FInputActionValue& InputValue);

	void AbilityInputHeld(FGameplayTag InputTag);

	void AbilityInputReleased(FGameplayTag InputTag);
};
