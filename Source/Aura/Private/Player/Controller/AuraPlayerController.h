// Thomas Learning Project

#pragma once

#include "CoreMinimal.h"
#include "PlayerController/CommonAbilityPlayerController.h"
#include "AuraPlayerController.generated.h"

struct FInputActionValue;


/// <summary>
/// Default player controller class used by this project
/// </summary>
UCLASS()
class AAuraPlayerController final : public ACommonAbilityPlayerController
{
	GENERATED_BODY()

protected:
	virtual void SetupInputComponent() override;

private:
	/* Used to move the character around. */
	void Move(const FInputActionValue& InputValue);
};
