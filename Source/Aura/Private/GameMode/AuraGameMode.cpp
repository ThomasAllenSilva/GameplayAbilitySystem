// Thomas Learning Project

#include "GameMode/AuraGameMode.h"

int AAuraGameMode::GetXPRewardForEnemy(const FGameplayTag& EnemyTag, const int EnemyLevel) const
{
	checkf(EnemiesXPReward.Contains(EnemyTag), TEXT("EnemiesXPReward Does Not Contain A Valid Key For The Tag: %s"), *EnemyTag.ToString());

	return EnemiesXPReward[EnemyTag].GetValueAtLevel(EnemyLevel);
}
