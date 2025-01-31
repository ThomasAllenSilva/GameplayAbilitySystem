// Thomas Hero Project

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "GameplayTagContainer.h"
#include "CommonAbilityPlayerController.generated.h"

class UDataAsset_InputConfig;
/**
 *
 */
UCLASS()
class COMMONABILITYSYSTEM_API ACommonAbilityPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	virtual void SetupInputComponent() override;

	virtual void AbilityInputTriggered(FGameplayTag InputTag);

	virtual void AbilityInputReleased(FGameplayTag InputTag);

private:
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UDataAsset_InputConfig> InputConfig;
};
