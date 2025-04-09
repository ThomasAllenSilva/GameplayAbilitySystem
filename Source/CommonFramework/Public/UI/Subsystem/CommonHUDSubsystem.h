// Thomas Learning Project

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/LocalPlayerSubsystem.h"
#include "CommonHUDSubsystem.generated.h"

struct FGameplayTag;
struct FWidgetContentInfo;
/**
 * 
 */
UCLASS()
class COMMONFRAMEWORK_API UCommonHUDSubsystem final : public ULocalPlayerSubsystem
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable)
	void PushToOverlayLayer(const FGameplayTag OverlayWidgetTag, const FWidgetContentInfo& WidgetContentInfo);

	UFUNCTION(BlueprintCallable)
	void RemoveFromOverlayLayer(const FGameplayTag OverlayWidgetTag, const FGameplayTag& WidgetTag);
};
