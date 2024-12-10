// Thomas Learning Project

#include "AbilitySystem/Data/AttributesInfoDataAsset.h"

FAuraAttributeInfo UAttributesInfoDataAsset::GetAttributeInfo(const FGameplayTag& AttributeTag) const
{
	const FAuraAttributeInfo* AttributeInfo = AttributesInfos.Find(AttributeTag);

	checkf(AttributeInfo, TEXT("Could Not Find Attribute Info For Tag: %s"), *AttributeTag.GetTagName().ToString());

	return *AttributeInfo;
}
