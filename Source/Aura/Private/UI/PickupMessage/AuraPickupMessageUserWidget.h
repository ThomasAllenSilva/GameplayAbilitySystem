// Thomas Learning Project

#pragma once

#include "CoreMinimal.h"

#include "Blueprint/UserWidget.h"

#include "GameplayTagContainer.h"

#include "AuraPickupMessageUserWidget.generated.h"

class UAbilitySystemComponent;

struct FGameplayEffectSpec;

struct FActiveGameplayEffectHandle;

UCLASS()
class UAuraPickupMessageUserWidget final : public UUserWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnRequestedPickupMessage(const FGameplayTag& Tag);

	virtual void NativeConstruct() override;

	virtual void BeginDestroy() override;

private:
	UPROPERTY(BlueprintReadWrite, Category = "Widget Settings", meta = (AllowPrivateAccess = "true"))
	FGameplayTag MessageTag;

	FDelegateHandle EffectAppliedDelegateHandle;

private:
	void OnGameplayEffectAppliedDelegateToSelf(UAbilitySystemComponent* ASC, const FGameplayEffectSpec& EffectSpec, FActiveGameplayEffectHandle EffectHandle);
};
