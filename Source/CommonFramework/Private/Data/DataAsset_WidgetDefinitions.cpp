// Thomas Learning Project


#include "DataAsset_WidgetDefinitions.h"

const FWidgetSetupSettings* UDataAsset_WidgetDefinitions::GetWidgetSettingsByTag(const FGameplayTag& Tag, bool& bFound) const
{
    const FWidgetSetupSettings* WidgetSetupSettings = WidgetsMap.Find(Tag);

    bFound = WidgetSetupSettings != nullptr;

    return WidgetSetupSettings;
}
