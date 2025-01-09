// Thomas Learning Project

#pragma once

#include "CoreMinimal.h"

#include "Components/ActorComponent.h"

#include "WidgetCreatorComponent.generated.h"

class UWidgetComponentSettings;

UENUM()
enum EWidgetCreationType
{
	AddToViewport,

	WidgetComponent
};

USTRUCT(BlueprintType)
struct FActorWidgets
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<UUserWidget> Widget;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TEnumAsByte<EWidgetCreationType> WidgetCreationType;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (EditCondition = "WidgetCreationType == EWidgetCreationType::WidgetComponent"))
	TObjectPtr<UWidgetComponentSettings> WidgetComponentSettings;
};

UCLASS(ClassGroup = (CommonFramework), meta = (BlueprintSpawnableComponent))
class COMMONFRAMEWORK_API UWidgetCreatorComponent final : public UActorComponent
{
	GENERATED_BODY()

public:
	UWidgetCreatorComponent();

protected:
	virtual void BeginPlay() override;

private:
	void CreateStartupWidgets();
private:
	UPROPERTY(EditDefaultsOnly)
	TArray<FActorWidgets> StartupWidgets;
};
