// Thomas Learning Project

#pragma once

#include "CoreMinimal.h"

#include "AbilitySystemComponent.h"

#include "AuraAbilitySystemComponent.generated.h"

UCLASS()
class UAuraAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()

	UAuraAbilitySystemComponent();

public:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditDefaultsOnly, Category = "Initialization", meta = (AllowPrivateAccess))
	TArray<TSubclassOf<UGameplayEffect>> InitializationEffects;
};
