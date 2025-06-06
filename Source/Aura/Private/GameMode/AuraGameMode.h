// Thomas Learning Project

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ScalableFloat.h"
#include "GameplayTagContainer.h"
#include "AuraGameMode.generated.h"

struct FScalableFloat;
struct FGameplayTag;

/**
 * Used to define global and shared settings for this game
 */
UCLASS()
class AAuraGameMode final : public AGameModeBase
{
	GENERATED_BODY()

public:
	/* Returns the amount of XP the enemy should reward the Killer, based on its level. */
	int GetXPRewardForEnemy(const FGameplayTag& EnemyTag, const int EnemyLevel) const;

private:
	/* Used by enemies to reward player XP when killing them */
	UPROPERTY(EditDefaultsOnly)
	TMap<FGameplayTag, FScalableFloat> EnemiesXPReward;
};
