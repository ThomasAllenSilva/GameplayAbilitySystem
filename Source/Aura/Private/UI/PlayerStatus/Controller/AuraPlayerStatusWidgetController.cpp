// Thomas Learning Project

#include "UI/PlayerStatus/Controller/AuraPlayerStatusWidgetController.h"

void UAuraPlayerStatusWidgetController::SetGasData(UPlayerGasData* GasData)
{
	PlayerGasData = GasData;

	check(GasData);
}
