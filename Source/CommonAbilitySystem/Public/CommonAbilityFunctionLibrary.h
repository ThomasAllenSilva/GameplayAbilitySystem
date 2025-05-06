// Thomas Hero Project

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "GameplayTagContainer.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "CommonAbilityFunctionLibrary.generated.h"

class UCommonAbilitySystemComponent;
class ACommonAbilityPlayerState;
class ACommonAbilityPlayerController;

/**
 *
 */
UCLASS()
class COMMONABILITYSYSTEM_API UCommonAbilityFunctionLibrary final : public UAbilitySystemBlueprintLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DefaultToSelf = "WorldContextObject"))
	static APlayerController* GetLocalPlayerController(const UObject* WorldContextObject);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DefaultToSelf = "WorldContextObject"))
	static APlayerState* GetLocalPlayerState(const UObject* WorldContextObject);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DefaultToSelf = "WorldContextObject"))
	static ACommonAbilityPlayerState* GetLocalCommonAbilityPlayerState(const UObject* WorldContextObject);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DefaultToSelf = "WorldContextObject"))
	static ACommonAbilityPlayerController* GetLocalCommonAbilityPlayerController(const UObject* WorldContextObject);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DefaultToSelf = "WorldContextObject"))
	static UCommonAbilitySystemComponent* GetLocalPlayerAbilitySystemComponent(const UObject* WorldContextObject);

	UFUNCTION(BlueprintCallable, BlueprintPure)
	static UCommonAbilitySystemComponent* GetCommonAbilitySystemComponentFromActor(AActor* Actor);

	UFUNCTION(BlueprintCallable, BlueprintPure)
	static UCommonAbilitySystemComponent* GetCommonAbilitySystemComponentFromASC(UAbilitySystemComponent* AbilitySystemComponent);

	UFUNCTION(BlueprintCallable, BlueprintPure)
	static float GetMaximumEffectCooldownRemainingForTag(const FGameplayTag Tag, const UAbilitySystemComponent* ASC);

	UFUNCTION(BlueprintCallable)
	static void AddGameplayTagToActorIfNone(AActor* Actor, const FGameplayTag& Tag);

	UFUNCTION(BlueprintCallable)
	static void CompletelyRemoveGameplayTagFromActor(AActor* Actor, const FGameplayTag& Tag);

	UFUNCTION(BlueprintCallable, BlueprintPure)
	static int GetInt32Max();

	UFUNCTION(BlueprintCallable, BlueprintPure)
	static float GetFloatBigNumber();

	UFUNCTION(BlueprintCallable, BlueprintPure)
	static const FString GetTagLastName(const FGameplayTag& Tag);
};
