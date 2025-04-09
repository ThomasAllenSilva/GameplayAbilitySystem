// Thomas Learning Project

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "CommonHUD.generated.h"

class UHUDLayoutUserWidget;

/**
 * 
 */
UCLASS()
class COMMONFRAMEWORK_API ACommonHUD : public AHUD
{
	GENERATED_BODY()

public:
	UHUDLayoutUserWidget* GetLayoutUserWidget();

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UHUDLayoutUserWidget> LayoutUserWidgetClass;

	UPROPERTY()
	TObjectPtr<UHUDLayoutUserWidget> LayoutUserWidgetInstance;
};
