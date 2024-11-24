// Thomas Learning Project

#pragma once

#include "CoreMinimal.h"

#include "GameFeatureAction.h"

#include "GameplayTagContainer.h"

#include "GameFeaturesSubsystem.h"
#include "Components/GameFrameworkComponentManager.h"
#include "GameFeatureAction_AddWidgets.generated.h"

USTRUCT()
struct AURA_API FGameFeatureWidgetEntry
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "Widgets")
	TSubclassOf<UUserWidget> WidgetClass;
};

UCLASS(meta = (DisplayName = "Add Widgets"))
class UGameFeatureAction_AddWidgets final : public UGameFeatureAction
{
	GENERATED_BODY()

public:
	//~UGameFeatureAction interface
	virtual void OnGameFeatureActivating(FGameFeatureActivatingContext& Context) override;
	//~End of UGameFeatureAction interface

private:
	void AddToWorld(const FWorldContext& WorldContext, const FGameFeatureStateChangeContext& ChangeContext);

	void HandleActorExtension(AActor* Actor, FName EventName, FGameFeatureStateChangeContext ChangeContext);

	void CreateWidgets(UWorld* World);

	void RemoveWidgets();

	UFUNCTION()
	void OnDestroyedHandlerActor(AActor* DestroyedActor);

	TSharedPtr<FComponentRequestHandle> Handler;
private:
	UPROPERTY(EditAnywhere, Category = "Widgets")
	TSoftClassPtr<AActor> ActorExtensionHandler;

	UPROPERTY(EditAnywhere, Category = "Widgets")
	TArray<FGameFeatureWidgetEntry> WidgetsList;

	TMap<FGameFeatureStateChangeContext, FDelegateHandle> GameInstanceStartHandles;

	TArray<UUserWidget*> CreatedWidgets;
};
