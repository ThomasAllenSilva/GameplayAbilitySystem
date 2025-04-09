// Thomas Learning Project

#include "Player/HUD/CommonHUD.h"
#include "UI/Widgets/HUDLayoutUserWidget.h"

UHUDLayoutUserWidget* ACommonHUD::GetLayoutUserWidget()
{
	if (LayoutUserWidgetInstance == nullptr)
	{
		LayoutUserWidgetInstance = CreateWidget<UHUDLayoutUserWidget>(GetOwningPlayerController(), LayoutUserWidgetClass);

		LayoutUserWidgetInstance->AddToViewport();
	}

	check(LayoutUserWidgetInstance);

	return LayoutUserWidgetInstance;
}

void ACommonHUD::BeginPlay()
{
	Super::BeginPlay();

	if (LayoutUserWidgetInstance == nullptr)
	{
		LayoutUserWidgetInstance = CreateWidget<UHUDLayoutUserWidget>(GetOwningPlayerController(), LayoutUserWidgetClass);

		LayoutUserWidgetInstance->AddToViewport();
	}
}
