// Thomas Learning Project

#pragma once

#include "CoreMinimal.h"

#include "GameFramework/PlayerState.h"

#include "AbilitySystemInterface.h"

#include "AuraPlayerState.generated.h"

class UAuraAbilitySystemComponent;

class UAuraAttributeSet;

class UPlayerGasData;

class UAuraPrimaryAttributeSet;

class UAuraSecondaryAttributeSet;

class UAuraVitalAttributeSet;

UCLASS()
class AAuraPlayerState final : public APlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	AAuraPlayerState();

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	virtual UAuraAttributeSet* GetAttributeSet() const;

	virtual void BeginPlay() override;

	FORCEINLINE UPlayerGasData* GetPlayerGasData() const { return PlayerGasData; }

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnExecutedBeginPlay();

private:
	UPROPERTY(EditAnywhere)
	TObjectPtr<UAuraAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY()
	TObjectPtr<UAuraAttributeSet> AttributeSet;

	UPROPERTY()
	TObjectPtr<UAuraPrimaryAttributeSet> PrimaryAttributeSet;

	UPROPERTY()
	TObjectPtr<UAuraSecondaryAttributeSet> SecondaryAttributeSet;

	UPROPERTY()
	TObjectPtr<UAuraVitalAttributeSet> VitalAttributeSet;

	UPROPERTY()
	TObjectPtr<UPlayerGasData> PlayerGasData;
};
