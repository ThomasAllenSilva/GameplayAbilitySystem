// Thomas Learning Project

#pragma once

#include "CoreMinimal.h"

#include "Blueprint/UserWidget.h"

#include "UI/Interfaces/Initializer/IAuraWidgetControllerInitializer.h"

#include "AuraPickupMessageUserWidgetView.generated.h"

class UAuraPickupWidgetController;

UCLASS()
class UAuraPickupMessageUserWidgetView final : public UUserWidget, public IAuraWidgetControllerInitializer
{
	GENERATED_BODY()

public:
	virtual void SetWidgetController(UObject* Controller) override;

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnRequestedPickupMessage(const FGameplayTag& MessageTag);

	virtual void BeginDestroy() override;

private:
	TObjectPtr<UAuraPickupWidgetController> WidgetController;
};
