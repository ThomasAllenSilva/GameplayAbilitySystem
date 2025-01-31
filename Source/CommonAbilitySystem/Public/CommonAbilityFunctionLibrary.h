// Thomas Hero Project

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "GameplayTagContainer.h"
#include "CommonAbilityFunctionLibrary.generated.h"

class UCommonAbilitySystemComponent;
class ACommonAbilityPlayerState;

/**
 * 
 */
UCLASS()
class COMMONABILITYSYSTEM_API UCommonAbilityFunctionLibrary final : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DefaultToSelf = "WorldContextObject"))
	static ACommonAbilityPlayerState* GetLocalPlayerState(const UObject* WorldContextObject);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DefaultToSelf = "WorldContextObject"))
	static UCommonAbilitySystemComponent* GetLocalPlayerAbilitySystemComponent(const UObject* WorldContextObject);

	UFUNCTION(BlueprintCallable)
	static void AddGameplayTagToActorIfNone(AActor* Actor, const FGameplayTag& Tag);
};
