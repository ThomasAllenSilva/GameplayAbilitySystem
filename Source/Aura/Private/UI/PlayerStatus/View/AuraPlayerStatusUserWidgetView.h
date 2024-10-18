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

private:
	UPROPERTY()
	TObjectPtr<UAuraPlayerStatusWidgetController> Controller;
};
