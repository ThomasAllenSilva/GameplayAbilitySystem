// Thomas Learning Project

#pragma once

#include "CoreMinimal.h"

#include "Engine/DataAsset.h"

#include "GameplayTagContainer.h"

#include "AuraInputConfigDataAsset.generated.h"

class UInputAction;

UCLASS()
class UAuraInputConfigDataAsset final : public UDataAsset
{
	GENERATED_BODY()
	
public:
	UInputAction* GetInputAction(const FGameplayTag& Tag);
	
	FORCEINLINE const TMap<FGameplayTag, UInputAction*> GetInputDefinitions() const { return InputDefinitions; }

private:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess))
	TMap<FGameplayTag, UInputAction*> InputDefinitions;
};
