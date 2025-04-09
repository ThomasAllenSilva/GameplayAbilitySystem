// Thomas Learning Project

#include "AbilitySystem/Data/DataAsset_AbilityInfo.h"

FAuraAbilityInfo UDataAsset_AbilityInfo::GetAbilityInfoByTag(const FGameplayTag& AbilityTag) const
{
	for (const FAuraAbilityInfo& Info : AbilityInfo)
	{
		if (Info.AbilityTag.MatchesTagExact(AbilityTag))
		{
			return Info;
		}
	}

	checkf(0, TEXT("Could not find AbilityInfo for tag %f"), *AbilityTag.ToString());

	return FAuraAbilityInfo();
}
