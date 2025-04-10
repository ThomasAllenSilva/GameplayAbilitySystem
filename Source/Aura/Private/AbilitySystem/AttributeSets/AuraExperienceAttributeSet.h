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
	ATTRIBUTE_ACCESSORS(UAuraExperienceAttributeSet, Level);
	ATTRIBUTE_ACCESSORS(UAuraExperienceAttributeSet, XP);
	ATTRIBUTE_ACCESSORS(UAuraExperienceAttributeSet, IncomingXP);

private:
	UPROPERTY(BlueprintReadOnly, Category = "Experience Meta Attributes", meta = (AllowPrivateAccess))
	FGameplayAttributeData Level;

	UPROPERTY(BlueprintReadOnly, Category = "Experience Meta Attributes", meta = (AllowPrivateAccess))
	FGameplayAttributeData XP;

	UPROPERTY(BlueprintReadOnly, Category = "Experience Meta Attributes", meta = (AllowPrivateAccess))
	FGameplayAttributeData IncomingXP;
};
