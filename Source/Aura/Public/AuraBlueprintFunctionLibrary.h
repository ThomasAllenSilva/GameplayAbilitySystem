// Thomas Learning Project

#pragma once

#include "CoreMinimal.h"

#include "Kismet/BlueprintFunctionLibrary.h"

#include "AuraBlueprintFunctionLibrary.generated.h"

UCLASS()
class AURA_API UAuraBlueprintFunctionLibrary final : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DefaultToSelf = "WorldContextObject"))
	static APlayerState* GetLocalPlayerState(const UObject* WorldContextObject);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DefaultToSelf = "WorldContextObject"))
	static UAuraAbilitySystemComponent* GetLocalPlayerAbilitySystemComponent(const UObject* WorldContextObject);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DefaultToSelf = "WorldContextObject"))
	static const UAuraAttributeSet* GetLocalPlayerAttributeSet(const UObject* WorldContextObject);

	UFUNCTION(BlueprintCallable, BlueprintPure)
	static const FString GetTagLastName(const FGameplayTag& Tag);

	UFUNCTION(BlueprintCallable, Category = "Game Features")
	static void LoadAndActivateGameFeature(const FString& PluginName);

	UFUNCTION(BlueprintCallable, Category = "Game Features")
	static void UnloadGameFeature(const FString& PluginName);
};
