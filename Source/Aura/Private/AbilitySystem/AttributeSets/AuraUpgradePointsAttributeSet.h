// Thomas Learning Project

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "AuraUpgradePointsAttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \

/**
 * Attributes that are used for in-game upgrades
 */
UCLASS()
class UAuraUpgradePointsAttributeSet final : public UAttributeSet
{
	GENERATED_BODY()
	
public:
	ATTRIBUTE_ACCESSORS(UAuraUpgradePointsAttributeSet, AttributePoints);
	ATTRIBUTE_ACCESSORS(UAuraUpgradePointsAttributeSet, AbilityPoints);

private:
	/* Points used to upgrade other attributes */
	UPROPERTY(BlueprintReadOnly, Category = "Upgrade Points Attributes", meta = (AllowPrivateAccess))
	FGameplayAttributeData AttributePoints;

	/* Points used to upgrade the ability level */
	UPROPERTY(BlueprintReadOnly, Category = "Upgrade Points Attributes", meta = (AllowPrivateAccess))
	FGameplayAttributeData AbilityPoints;
};
