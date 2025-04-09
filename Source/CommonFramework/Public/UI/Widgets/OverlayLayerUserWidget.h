// Thomas Learning Project

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "HUDLayoutUserWidget.h"
#include "OverlayLayerUserWidget.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class COMMONFRAMEWORK_API UOverlayLayerUserWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void PushWidget(const FWidgetContentInfo& WidgetContentInfo);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void RemoveWidget(const FGameplayTag& WidgetTag);

	UFUNCTION(BlueprintCallable)
	void Show();

	UFUNCTION(BlueprintCallable)
	void Collapse();

	UFUNCTION(BlueprintCallable)
	void Hide();

	UFUNCTION(BlueprintCallable)
	bool HasWidgetInsideOverlay(const FGameplayTag& WidgetTag) const;

private:
	UPROPERTY(BlueprintReadOnly, meta = (AllowPrivateAccess))
	TMap<FGameplayTag, UUserWidget*> ActiveWidgets;
};
