// Thomas Learning Project

#pragma once

#include "CoreMinimal.h"

#include "GameFramework/PlayerState.h"

#include "AbilitySystemInterface.h"

#include "AuraPlayerState.generated.h"

class UAuraAbilitySystemComponent;

class UAuraAttributeSet;


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

	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere)
	TObjectPtr<UAuraAbilitySystemComponent> AbilitySystemComponent;
};
