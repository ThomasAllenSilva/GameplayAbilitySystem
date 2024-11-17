// Thomas Learning Project

#pragma once

#include "CoreMinimal.h"

#include "Blueprint/UserWidget.h"

#include "UI/Interfaces/Initializer/IAuraWidgetControllerInitializer.h"

#include "AuraPlayerStatusUserWidgetView.generated.h"

class UAuraPlayerStatusWidgetController;

UCLASS()
class UAuraPlayerStatusUserWidgetView final : public UUserWidget, public IAuraWidgetControllerInitializer
{
	GENERATED_BODY()

public:
	virtual void SetWidgetController(UObject* Controller) override;

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
