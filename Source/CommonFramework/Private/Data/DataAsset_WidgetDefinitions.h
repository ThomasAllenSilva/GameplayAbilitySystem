// Thomas Learning Project

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "DataAsset_WidgetDefinitions.generated.h"

class UDataAsset_WidgetComponentConfigs;
struct FGameplayTag;

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
	FGameplayTag WidgetTag;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TEnumAsByte<EWidgetCreationType> WidgetCreationType = EWidgetCreationType::AddToViewport;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (EditCondition = "WidgetCreationType == EWidgetCreationType::AddToViewport"))
	FGameplayTag OverlayLayerTag;

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
	const TArray<FWidgetSetupSettings> GetStartupWidgets() const { return StartupWidgets; }

	const FWidgetSetupSettings* GetWidgetSettingsByTag(const FGameplayTag& Tag, bool& bFound) const;

private:
	UPROPERTY(EditDefaultsOnly, meta = (TitleProperty = "{Widget}"))
	TArray<FWidgetSetupSettings> StartupWidgets;

	UPROPERTY(EditDefaultsOnly)
	TMap<FGameplayTag, FWidgetSetupSettings> WidgetsMap;
};
