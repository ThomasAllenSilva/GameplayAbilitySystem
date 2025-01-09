// Thomas Learning Project

#pragma once

#include "CoreMinimal.h"

#include "Engine/GameInstance.h"

#include "AuraGameInstance.generated.h"

UCLASS()
class AURA_API UAuraGameInstance final : public UGameInstance
{
	GENERATED_BODY()

public:
	UAuraGameInstance();

	virtual void StartGameInstance() override;

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnBeforeStartGameInstance();
};
