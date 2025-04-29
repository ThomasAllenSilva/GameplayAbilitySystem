// Thomas Learning Project

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "GameplayTagContainer.h"
#include "AsyncAction_CooldownChanged.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnCooldownChanged);

class UAbilitySystemComponent;

/**
 *
 */
UCLASS(BlueprintType, meta = (ExposedAsyncProxy = AsyncTask))
class UAsyncAction_CooldownChanged final : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"))
	static UAsyncAction_CooldownChanged* ListenForCooldownChange(UAbilitySystemComponent* AbilitySystemComponent, FGameplayTag CooldownTag);

	UFUNCTION(BlueprintCallable)
	void EndTask();

	UFUNCTION(BlueprintCallable)
	float GetRemainingTime() const;

public:
	UPROPERTY(BlueprintAssignable)
	FOnCooldownChanged OnCooldownStart;

	UPROPERTY(BlueprintAssignable)
	FOnCooldownChanged OnCooldownEnd;

private:
	void OnCooldownTagCountChanged(const FGameplayTag Tag, int32 TagCount) const;

private:
	UPROPERTY()
	FGameplayTag CooldownTag;

	UPROPERTY()
	UAbilitySystemComponent* OwningASC;
};
