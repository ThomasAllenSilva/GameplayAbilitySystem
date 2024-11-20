// Thomas Learning Project


#include "UI/PickupsMessages/View/AuraPickupMessageUserWidgetView.h"

#include "UI/PickupsMessages/Controller/AuraPickupWidgetController.h"

void UAuraPickupMessageUserWidgetView::SetWidgetController(UObject* Controller)
{
	//WidgetController = CastChecked<UAuraPickupWidgetController>(Controller);

	//WidgetController->OnRequestedPickupMessage.AddDynamic(this, &UAuraPickupMessageUserWidgetView::OnRequestedPickupMessage);
}

void UAuraPickupMessageUserWidgetView::BeginDestroy()
{
	Super::BeginDestroy();

	if (WidgetController != nullptr)
	{
		WidgetController->OnRequestedPickupMessage.RemoveDynamic(this, &UAuraPickupMessageUserWidgetView::OnRequestedPickupMessage);
	}
}
