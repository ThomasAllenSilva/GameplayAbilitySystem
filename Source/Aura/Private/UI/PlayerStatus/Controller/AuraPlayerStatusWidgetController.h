// Thomas Learning Project

#pragma once

#include "CoreMinimal.h"

#include "UObject/NoExportTypes.h"

#include "AuraPlayerStatusWidgetController.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FHealthValueChangedSignature, float, NewHealthValue);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMaxHealthValueChangedSignature, float, NewMaxHealthValue);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FManaValueChangedSignature, float, NewManaValue);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMaxManaValueChangedSignature, float, NewMaxManaValue);

class UPlayerGasData;

struct FOnAttributeChangeData;

UCLASS()
class UAuraPlayerStatusWidgetController final : public UObject
{
	GENERATED_BODY()
	
public:
	void SetGasData(UPlayerGasData* GasData);

	void BroadcastInitialValues();

public:
	UPROPERTY(BlueprintAssignable, Category = "Events|Attributes")
	FHealthValueChangedSignature OnHealthValueChanged;

	UPROPERTY(BlueprintAssignable, Category = "Events|Attributes")
	FMaxHealthValueChangedSignature OnMaxHealthValueChanged;

	UPROPERTY(BlueprintAssignable, Category = "Events|Attributes")
	FManaValueChangedSignature OnManaValueChanged;

	UPROPERTY(BlueprintAssignable, Category = "Events|Attributes")
	FMaxManaValueChangedSignature OnMaxManaValueChanged;

private:
	UPROPERTY()
	TObjectPtr<UPlayerGasData> PlayerGasData;

private:
	void BindAttributeDelegatesCallbacks();

	void OnHealthAttribueValueChanged(const FOnAttributeChangeData& HealthData) const;

	void OnMaxHealthAttribueValueChanged(const FOnAttributeChangeData& MaxHealthData) const;

	void OnManaAttribueValueChanged(const FOnAttributeChangeData& ManaData) const;

	void OnMaxManaAttribueValueChanged(const FOnAttributeChangeData& MaxManaData) const;
};
