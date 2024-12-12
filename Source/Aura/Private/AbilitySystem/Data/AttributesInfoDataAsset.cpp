// Thomas Learning Project

#include "AbilitySystem/Data/AttributesInfoDataAsset.h"

#include "Debug.h"
FAuraAttributeInfo UAttributesInfoDataAsset::GetAttributeInfo(const FGameplayTag& AttributeTag) const
{
	const FAuraAttributeInfo* AttributeInfo = AttributesInfos.Find(AttributeTag);

	ASSERT_CONDITION(AttributesInfos.Contains(AttributeTag), FString::Printf(TEXT("Could Not Find Attribute Info For Tag: %s"), *AttributeTag.GetTagName().ToString()));

	return *AttributeInfo;
}
