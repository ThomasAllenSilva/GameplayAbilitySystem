// Thomas Learning Project

#include "UI/PlayerStatus/View/AuraPlayerStatusUserWidgetView.h"

#include "UI/PlayerStatus/Controller/AuraPlayerStatusWidgetController.h"

void UAuraPlayerStatusUserWidgetView::SetWidgetController(UObject* WidgetController)
{
	Controller = CastChecked<UAuraPlayerStatusWidgetController>(WidgetController);

	Controller->OnHealthValueChanged.AddDynamic(this, &UAuraPlayerStatusUserWidgetView::OnHealthValueChanged);

	Controller->OnMaxHealthValueChanged.AddDynamic(this, &UAuraPlayerStatusUserWidgetView::OnMaxHealthValueChanged);

	Controller->OnManaValueChanged.AddDynamic(this, &UAuraPlayerStatusUserWidgetView::OnManaValueChanged);

	Controller->OnMaxManaValueChanged.AddDynamic(this, &UAuraPlayerStatusUserWidgetView::OnMaxManaValueChanged);

	check(Controller);
}
