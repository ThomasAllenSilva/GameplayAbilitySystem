// Thomas Learning Project

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "CommonAbilitySystemComponent.generated.h"

DECLARE_MULTICAST_DELEGATE(FInitializedSignature);

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

	FORCEINLINE bool GetIsInitialized() const { return bIsInitialized; }


public:
	FInitializedSignature OnInitialized;

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditDefaultsOnly)
	TArray<TObjectPtr<UDataAsset_CommonAbilitySet>> AbilitySets;

	bool bIsInitialized;
};
