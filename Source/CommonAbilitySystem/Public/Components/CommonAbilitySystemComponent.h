// Thomas Learning Project

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "CommonAbilitySystemComponent.generated.h"

class UDataAsset_CommonAbilitySet;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FInitializedAbilitySetsSignature);

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

	UFUNCTION(BlueprintPure)
	float GetGameplayAttributeValueChecked(FGameplayAttribute Attribute);

	/* Returns the tag identifier of this component. It may return 'None' if it's not set */
	UFUNCTION(BlueprintCallable)
	const FGameplayTag& GetTagID() const;

	UPROPERTY(BlueprintAssignable) 
	FInitializedAbilitySetsSignature OnInitializedAbilitySets;

	
private:
	UPROPERTY(EditDefaultsOnly)
	TArray<TObjectPtr<UDataAsset_CommonAbilitySet>> AbilitySets;

	/* Unique tag used to identify this AbilitySystemComponent. In RPG games this can be used to define an ASC class (Warrior, Elementalist, etc.) */
	UPROPERTY(EditDefaultsOnly)
	FGameplayTag TagID;
};
