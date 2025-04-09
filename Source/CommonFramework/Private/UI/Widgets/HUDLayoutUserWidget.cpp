// Thomas Learning Project

#include "UI/Widgets/HUDLayoutUserWidget.h"

FWidgetContentInfo::FWidgetContentInfo()
{
}

FWidgetContentInfo::FWidgetContentInfo(FGameplayTag InWidgetTag, UUserWidget* InWidgetInstance)
{
	WidgetTag = InWidgetTag;
	WidgetInstance = InWidgetInstance;
}
