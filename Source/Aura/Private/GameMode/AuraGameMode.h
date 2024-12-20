// Thomas Learning Project

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "AuraGameMode.generated.h"

/**
 * 
 */
UCLASS()
class AAuraGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	virtual void InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage);

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnInitGame();
};
