// Thomas Learning Project

#pragma once

#include "CoreMinimal.h"

#include "AbilitySystemComponent.h"

#include "AuraAbilitySystemComponent.generated.h"

UCLASS()
class UAuraAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;

	virtual void AbilityLocalInputPressed(int32 InputID) override;

private:
	UPROPERTY(EditDefaultsOnly, Category = "Initialization", meta = (AllowPrivateAccess))
	TArray<TSubclassOf<UGameplayEffect>> InitializationEffects;

	UPROPERTY(EditDefaultsOnly, Category = "Initialization", meta = (AllowPrivateAccess))
	TArray<TSubclassOf<UGameplayAbility>> InitialAbilities;
};
