// Thomas Learning Project

#include "UI/PlayerStatus/View/AuraPlayerStatusUserWidgetView.h"

#include "UI/PlayerStatus/Controller/AuraPlayerStatusWidgetController.h"

void UAuraPlayerStatusUserWidgetView::SetWidgetController(UAuraPlayerStatusWidgetController* WidgetController)
{
	Controller = WidgetController;

	check(Controller);
}
