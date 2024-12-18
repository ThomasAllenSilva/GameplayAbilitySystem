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
	void AbilityInputHeld(const FGameplayTag& InputTag);

	void AbilityInputReleased(const FGameplayTag& InputTag);

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditDefaultsOnly, Category = "Initialization", meta = (AllowPrivateAccess))
	TArray<TSubclassOf<UGameplayEffect>> InitializationEffects;

	UPROPERTY(EditDefaultsOnly, Category = "Initialization", meta = (AllowPrivateAccess))
	TArray<TSubclassOf<UGameplayAbility>> InitialAbilities;
};
