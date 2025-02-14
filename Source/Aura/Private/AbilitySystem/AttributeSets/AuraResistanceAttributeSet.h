// Thomas Learning Project

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AuraResistanceAttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \

/**
 *
 */
UCLASS()
class UAuraResistanceAttributeSet final : public UAttributeSet
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadOnly, Category = "Resistance Attributes")
	FGameplayAttributeData FireResistance;
	ATTRIBUTE_ACCESSORS(UAuraResistanceAttributeSet, FireResistance);

	UPROPERTY(BlueprintReadOnly, Category = "Resistance Attributes")
	FGameplayAttributeData LightningResistance;
	ATTRIBUTE_ACCESSORS(UAuraResistanceAttributeSet, LightningResistance);

	UPROPERTY(BlueprintReadOnly, Category = "Resistance Attributes")
	FGameplayAttributeData ArcaneResistance;
	ATTRIBUTE_ACCESSORS(UAuraResistanceAttributeSet, ArcaneResistance);

	UPROPERTY(BlueprintReadOnly, Category = "Resistance Attributes")
	FGameplayAttributeData PhysicalResistance;
	ATTRIBUTE_ACCESSORS(UAuraResistanceAttributeSet, PhysicalResistance);
};
