// Thomas Learning Project

#pragma once

#include "CoreMinimal.h"

#include "Components/ActorComponent.h"

#include "GameplayTagContainer.h"

#include "WidgetCreatorComponent.generated.h"

class UWidgetDefinitions;

struct FWidgetSetupSettings;

UCLASS(ClassGroup = (CommonFramework), meta = (BlueprintSpawnableComponent))
class COMMONFRAMEWORK_API UWidgetCreatorComponent final : public UActorComponent
{
	GENERATED_BODY()

public:
	UWidgetCreatorComponent();

	UUserWidget* CreateWidgetByTag(const FGameplayTag& Tag);

protected:
	virtual void BeginPlay() override;

private:
	void CreateStartupWidgets();

	UUserWidget* ConstructWidgetUsingSettings(const FWidgetSetupSettings& WidgetSetupSettings);

private:
	UPROPERTY(EditDefaultsOnly)
	TArray<TObjectPtr<UWidgetDefinitions>> WidgetDefinitions;
};
