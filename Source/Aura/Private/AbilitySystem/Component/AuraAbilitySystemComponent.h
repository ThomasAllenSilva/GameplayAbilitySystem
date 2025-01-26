// Thomas Learning Project

#pragma once

#include "CoreMinimal.h"

#include "AbilitySystemComponent.h"

#include "AuraAbilitySystemComponent.generated.h"

class UCharacterClassSettings;

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
	void InitializeComponentConfiguration(const UCharacterClassSettings* ClassSettings);

private:
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UCharacterClassSettings> CharacterClassConfiguration;
};
