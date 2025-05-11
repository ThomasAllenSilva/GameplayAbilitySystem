// Thomas Learning Project

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "WidgetCreatorComponent.generated.h"

class UDataAsset_WidgetDefinitions;
struct FWidgetSetupSettings;

UCLASS(ClassGroup = (CommonFramework), meta = (BlueprintSpawnableComponent))
class COMMONFRAMEWORK_API UWidgetCreatorComponent final : public UActorComponent
{
	GENERATED_BODY()

public:
	UWidgetCreatorComponent();

	UFUNCTION(BlueprintCallable)
	void CreateDefaultWidgets();

private:
	UUserWidget* ConstructWidgetUsingSettings(const FWidgetSetupSettings& WidgetSetupSettings);

	UFUNCTION(BlueprintCallable)
	TSubclassOf<UUserWidget> GetWidgetByTagChecked(const FGameplayTag WidgetTag) const;

private:
	UPROPERTY(EditDefaultsOnly)
	TArray<TObjectPtr<UDataAsset_WidgetDefinitions>> WidgetDefinitions;
};
