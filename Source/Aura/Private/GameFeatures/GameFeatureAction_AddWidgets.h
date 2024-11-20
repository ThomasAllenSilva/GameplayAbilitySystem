// Thomas Learning Project

#pragma once

#include "CoreMinimal.h"

#include "GameFeatureAction.h"

#include "GameplayTagContainer.h"

#include "GameFeaturesSubsystem.h"

#include "GameFeatureAction_AddWidgets.generated.h"

USTRUCT()
struct AURA_API FGameFeatureWidgetEntry
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "Widgets", meta = (AllowAbstract = "True"))
	TSoftClassPtr<UUserWidget> WidgetClass;

	UPROPERTY(EditAnywhere, Category = "Widgets")
	FGameplayTag Layer;
};

UCLASS(meta = (DisplayName = "Add Widgets"))
class UGameFeatureAction_AddWidgets final : public UGameFeatureAction
{
	GENERATED_BODY()
public:
	//~UGameFeatureAction interface
	virtual void OnGameFeatureActivating(FGameFeatureActivatingContext& Context) override;
	virtual void OnGameFeatureDeactivating(FGameFeatureDeactivatingContext& Context) override;
	//~End of UGameFeatureAction interface

private:
	void HandleGameInstanceStart(UGameInstance* GameInstance, FGameFeatureStateChangeContext ChangeContext);

	void AddToWorld(const FWorldContext& WorldContext, const FGameFeatureStateChangeContext& ChangeContext);

	void HandleActorExtension(AActor* Actor, FName EventName, FGameFeatureStateChangeContext ChangeContext);

	void CreateWidgets();

	void RemoveWidgets();

private:	
	UPROPERTY(EditAnywhere, Category = "Widgets")
	TArray<FGameFeatureWidgetEntry> WidgetsList;

	TMap<FGameFeatureStateChangeContext, FDelegateHandle> GameInstanceStartHandles;
};
