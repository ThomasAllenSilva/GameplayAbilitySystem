// Thomas Learning Project

#pragma once

#include "CoreMinimal.h"

#include "UObject/NoExportTypes.h"

#include "PlayerGasData.generated.h"

class UAuraAbilitySystemComponent;

class UAuraAttributeSet;

struct FOnAttributeChangeData;

UCLASS()
class UPlayerGasData final : public UObject
{
	GENERATED_BODY()

public:
	FORCEINLINE UAuraAbilitySystemComponent* GetAbilitySystemComponent() const { return AbilitySystemComponent; }

	FORCEINLINE UAuraAttributeSet* GetAttributeSet() const { return AttributeSet; }

	void InitializeData(UAuraAbilitySystemComponent* InASC, UAuraAttributeSet* InAttributeSet);

private:
	UPROPERTY()
	TObjectPtr<UAuraAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY()
	TObjectPtr<UAuraAttributeSet> AttributeSet;
};
