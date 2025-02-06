// Thomas Learning Project

#pragma once

#include "CoreMinimal.h"

#include "PlayerController/CommonAbilityPlayerController.h"

#include "AuraPlayerController.generated.h"

struct FInputActionValue;

UCLASS()
class AAuraPlayerController final : public ACommonAbilityPlayerController
{
	GENERATED_BODY()

protected:
	virtual void SetupInputComponent() override;

private:
	void Move(const FInputActionValue& InputValue);
};
