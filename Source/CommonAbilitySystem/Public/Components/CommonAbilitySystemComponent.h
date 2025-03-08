// Thomas Learning Project

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "CommonAbilitySystemComponent.generated.h"

class UDataAsset_CommonAbilitySet;

/**
 *
 */
UCLASS()
class COMMONABILITYSYSTEM_API UCommonAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()

public:
	virtual void AbilityInputTriggered(const FGameplayTag& InputTag);

	virtual void AbilityInputReleased(const FGameplayTag& InputTag);

	void InitializeAbilitySets();

private:
	UPROPERTY(EditDefaultsOnly)
	TArray<TObjectPtr<UDataAsset_CommonAbilitySet>> AbilitySets;
};
