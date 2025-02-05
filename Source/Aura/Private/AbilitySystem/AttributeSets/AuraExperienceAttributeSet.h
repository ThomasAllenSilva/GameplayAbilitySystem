// Thomas Learning Project

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AuraExperienceAttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \

UCLASS()
class UAuraExperienceAttributeSet final : public UAttributeSet
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintReadOnly, Category = "Experience Attributes")
	FGameplayAttributeData Level;
	ATTRIBUTE_ACCESSORS(UAuraExperienceAttributeSet, Level);
};
