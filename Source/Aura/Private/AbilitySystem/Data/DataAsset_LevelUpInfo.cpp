// Thomas Learning Project

#include "AbilitySystem/Data/DataAsset_LevelUpInfo.h"

int UDataAsset_LevelUpInfo::FindLevelForXP(int InXP) const
{
	for (int i = 1; i < LevelsInfo.Num(); i++)
	{
		if (InXP >= LevelsInfo[i].XPRequirement)
		{
			continue;
		}

		else
		{
			return i;
		}
	}

	return LevelsInfo.Num() - 1; //if the XP is higher than all the levels xp requirement, we simply return the max level
}

FLevelUpInfo UDataAsset_LevelUpInfo::GetInformationForLevel(int LevelIndex) const
{
	check(LevelIndex > 0);
	check(LevelIndex < LevelsInfo.Num());

	return LevelsInfo[LevelIndex];
}
