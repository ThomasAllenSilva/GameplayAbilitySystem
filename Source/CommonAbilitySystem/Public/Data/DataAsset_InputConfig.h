// Thomas Hero Project

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "DataAsset_InputConfig.generated.h"

class UInputAction;
class UInputMappingContext;

/**
 * 
 */
UCLASS()
class COMMONABILITYSYSTEM_API UDataAsset_InputConfig final : public UDataAsset
{
	GENERATED_BODY()
	
public:
	FORCEINLINE const UInputAction* GetInputActionByTag(const FGameplayTag& InputTag) const { return NativeInputActions.FindChecked(InputTag); }

	FORCEINLINE const TMap<FGameplayTag, TObjectPtr<UInputAction>>& GetAbilityInputActions() const { return AbilityInputActions; }

	FORCEINLINE const UInputMappingContext* GetInputMappingContext() const { return InputMappingContext; }

	FORCEINLINE int GetMappingContextPriority() const { return MappingContextPriority; }

private:
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UInputMappingContext> InputMappingContext;

	UPROPERTY(EditDefaultsOnly)
	int MappingContextPriority;

	UPROPERTY(EditDefaultsOnly)
	TMap<FGameplayTag, TObjectPtr<UInputAction>> NativeInputActions;

	UPROPERTY(EditDefaultsOnly)
	TMap<FGameplayTag, TObjectPtr<UInputAction>> AbilityInputActions;
};
