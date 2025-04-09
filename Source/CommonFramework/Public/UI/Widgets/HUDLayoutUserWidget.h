// Thomas Learning Project

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameplayTagContainer.h"
#include "HUDLayoutUserWidget.generated.h"

class UOverlayLayerUserWidget;

USTRUCT(BlueprintType)
struct FWidgetContentInfo
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly)
	FGameplayTag WidgetTag;

	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UUserWidget> WidgetInstance;

	FWidgetContentInfo();

	FWidgetContentInfo(FGameplayTag InWidgetTag, UUserWidget* InWidgetInstance);
};

/**
 * 
 */
UCLASS()
class COMMONFRAMEWORK_API UHUDLayoutUserWidget final : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void PushToOverlayLayer(const FGameplayTag& OverlayWidgetTag, const FWidgetContentInfo& WidgetContentInfo);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void RemoveFromOverlayLayer(const FGameplayTag& OverlayWidgetTag,  const FGameplayTag& WidgetTag);

protected:
	UFUNCTION(BlueprintCallable)
	UOverlayLayerUserWidget* GetOverlayLayer(const FGameplayTag& OverlayWidgetTag) const { return *OverlayLayers.Find(OverlayWidgetTag); };

private:
	UPROPERTY(BlueprintReadOnly, meta = (AllowPrivateAccess))
	TMap<FGameplayTag, UOverlayLayerUserWidget*> OverlayLayers;
};
