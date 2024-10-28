// Thomas Learning Project

#pragma once

#include "CoreMinimal.h"

#include "Blueprint/UserWidget.h"

#include "AuraPlayerStatusUserWidgetView.generated.h"

class UAuraPlayerStatusWidgetController;

UCLASS()
class UAuraPlayerStatusUserWidgetView final : public UUserWidget
{
	GENERATED_BODY()
	
public:
	void SetWidgetController(UAuraPlayerStatusWidgetController* WidgetController);

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnHealthValueChanged(float NewHealthValue);

	UFUNCTION(BlueprintImplementableEvent)
	void OnMaxHealthValueChanged(float NewMaxHealthValue);

	UFUNCTION(BlueprintImplementableEvent)
	void OnManaValueChanged(float NewManaValue);

	UFUNCTION(BlueprintImplementableEvent)
	void OnMaxManaValueChanged(float NewMaxManaValue);

private:
	TObjectPtr<UAuraPlayerStatusWidgetController> Controller;
};
