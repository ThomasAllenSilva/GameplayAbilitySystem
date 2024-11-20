// Thomas Learning Project

#pragma once

#include "CoreMinimal.h"

#include "GameFramework/HUD.h"

#include "AuraHUD.generated.h"

UCLASS()
class AAuraHUD final : public AHUD
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintImplementableEvent)
	void AddWidgetToLayer(const UUserWidget* Widget, const FGameplayTag& LayerTag);
};
