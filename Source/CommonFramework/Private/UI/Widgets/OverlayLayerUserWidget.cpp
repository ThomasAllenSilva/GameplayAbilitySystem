// Thomas Learning Project

#include "UI/Widgets/OverlayLayerUserWidget.h"

void UOverlayLayerUserWidget::Show()
{
	SetVisibility(ESlateVisibility::SelfHitTestInvisible);
}

void UOverlayLayerUserWidget::Collapse()
{
	SetVisibility(ESlateVisibility::Collapsed);
}

void UOverlayLayerUserWidget::Hide()
{
	SetVisibility(ESlateVisibility::Hidden);
}

bool UOverlayLayerUserWidget::HasWidgetInsideOverlay(const FGameplayTag& WidgetTag) const
{
	return ActiveWidgets.Contains(WidgetTag);
}
