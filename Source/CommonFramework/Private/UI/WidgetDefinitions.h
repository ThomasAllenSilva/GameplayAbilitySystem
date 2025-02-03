// Thomas Learning Project

#pragma once

#include "CoreMinimal.h"

#include "Engine/DataAsset.h"

#include "GameplayTagContainer.h"

#include "WidgetComponentSettings.h"

#include "WidgetDefinitions.generated.h"

UENUM(BlueprintType)
enum class EWidgetCreationType
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
	EWidgetCreationType WidgetCreationType;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (EditCondition = "WidgetCreationType == EWidgetCreationType::WidgetComponent"))
	TObjectPtr<UWidgetComponentSettings> WidgetComponentSettings;
};

UCLASS()
class COMMONFRAMEWORK_API UWidgetDefinitions final : public UDataAsset
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
