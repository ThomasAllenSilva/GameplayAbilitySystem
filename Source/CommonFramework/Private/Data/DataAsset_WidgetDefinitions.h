// Thomas Learning Project

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "DataAsset_WidgetDefinitions.generated.h"

class UDataAsset_WidgetComponentConfigs;

UENUM(BlueprintType)
enum EWidgetCreationType
{
	AddToViewport,

	WidgetComponent
};

USTRUCT(BlueprintType)
struct FWidgetSetupSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<UUserWidget> Widget;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TEnumAsByte<EWidgetCreationType> WidgetCreationType;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (EditCondition = "WidgetCreationType == EWidgetCreationType::WidgetComponent"))
	TObjectPtr<UDataAsset_WidgetComponentConfigs> WidgetComponentSettings;
};

/**
 * 
 */
UCLASS()
class COMMONFRAMEWORK_API UDataAsset_WidgetDefinitions final : public UDataAsset
{
	GENERATED_BODY()

public:
	FORCEINLINE const TArray<FWidgetSetupSettings> GetStartupWidgets() const { return StartupWidgets; }

	FORCEINLINE const FWidgetSetupSettings* GetWidgetSettingsByTag(const FGameplayTag& Tag) const { return WidgetSettingsMap.Find(Tag); }

private:
	UPROPERTY(EditDefaultsOnly)
	TArray<FWidgetSetupSettings> StartupWidgets;

	UPROPERTY(EditDefaultsOnly)
	TMap<FGameplayTag, FWidgetSetupSettings> WidgetSettingsMap;
};
