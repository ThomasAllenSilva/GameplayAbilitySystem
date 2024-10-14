// Thomas Learning Project

#pragma once

#include "CoreMinimal.h"

#include "GameFramework/PlayerState.h"

#include "AbilitySystemInterface.h"

#include "AuraPlayerState.generated.h"

class UAuraAbilitySystemComponent;

class UAuraAttributeSet;

UCLASS()
class AAuraPlayerState final : public APlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()
public:
	AAuraPlayerState();

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	virtual UAuraAttributeSet* GetAttributeSet() const;

	virtual void BeginPlay() override;

private:
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UAuraAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UAuraAttributeSet> AttributeSet;
};
