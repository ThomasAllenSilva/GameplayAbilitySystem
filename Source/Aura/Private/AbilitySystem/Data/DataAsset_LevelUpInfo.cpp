// Thomas Learning Project

#include "AbilitySystem/Data/DataAsset_LevelUpInfo.h"

int UDataAsset_LevelUpInfo::FindLevelFromXP(int InXP) const
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

	return 0;
}

FLevelUpInfo UDataAsset_LevelUpInfo::GetInformationForLevel(int LevelIndex) const
{
	check(LevelIndex > 0);
	check(LevelIndex < LevelsInfo.Num());

	return LevelsInfo[LevelIndex];
}
