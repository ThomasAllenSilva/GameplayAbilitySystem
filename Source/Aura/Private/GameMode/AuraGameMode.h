// Thomas Learning Project

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "AuraGameMode.generated.h"

class UCharacterClassConfigurationInfo;

UCLASS()
class AAuraGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	virtual void InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage);

	FORCEINLINE UCharacterClassConfigurationInfo* GetCharacterClassConfigurationInfo() const { return CharacterClassConfigurationInfo; }

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnInitGame();

private:
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UCharacterClassConfigurationInfo> CharacterClassConfigurationInfo;
};
