// Thomas Learning Project

#pragma once

#include "CoreMinimal.h"

#include "GameFramework/PlayerState.h"

#include "AbilitySystemInterface.h"

#include "AuraPlayerState.generated.h"

class UAuraAbilitySystemComponent;

class UAuraAttributeSet;

class UPlayerGasData;

class UAuraPlayerStatusUserWidgetView;

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

private:
	UPROPERTY()
	TObjectPtr<UAuraAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY()
	TObjectPtr<UAuraAttributeSet> AttributeSet;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UAuraPlayerStatusUserWidgetView> PlayerStatusWidget;

	UPROPERTY()
	TObjectPtr<UPlayerGasData> PlayerGasData;

private:
	void CreateAttributesStatusWidget();
};
