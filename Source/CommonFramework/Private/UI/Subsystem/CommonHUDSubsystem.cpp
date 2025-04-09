// Thomas Learning Project

#include "UI/Subsystem/CommonHUDSubsystem.h"
#include "UI/Widgets/HUDLayoutUserWidget.h"
#include "Player/HUD/CommonHUD.h"

void UCommonHUDSubsystem::PushToOverlayLayer(const FGameplayTag OverlayWidgetTag, const FWidgetContentInfo& WidgetContentInfo)
{
	ACommonHUD* CommonHUD = GetLocalPlayerChecked()->PlayerController->GetHUD<ACommonHUD>();

	CommonHUD->GetLayoutUserWidget()->PushToOverlayLayer(OverlayWidgetTag, WidgetContentInfo);
}

void UCommonHUDSubsystem::RemoveFromOverlayLayer(const FGameplayTag OverlayWidgetTag, const FGameplayTag& WidgetTag)
{
	ACommonHUD* CommonHUD = GetLocalPlayerChecked()->PlayerController->GetHUD<ACommonHUD>();

	CommonHUD->GetLayoutUserWidget()->RemoveFromOverlayLayer(OverlayWidgetTag, WidgetTag);
}
