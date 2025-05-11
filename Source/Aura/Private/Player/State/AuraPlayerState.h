// Thomas Learning Project

#pragma once

#include "CoreMinimal.h"
#include "PlayerState/CommonAbilityPlayerState.h"
#include "AbilitySystem/Interfaces/AuraExperienceInterface.h"

#include "AuraPlayerState.generated.h"

class UDataAsset_LevelUpInfo;

/**
 * Player state class used by this project
 * It holds GAS information about the player
 */
UCLASS()
class AAuraPlayerState final : public ACommonAbilityPlayerState, public IAuraExperienceInterface
{
	GENERATED_BODY()

public:
	UDataAsset_LevelUpInfo* GetLevelUpInfo() const;

	//~ Begin AuraExperience Interface
	/* Returns the current level that this character should be based on the XP param. */
	virtual int GetLevelForXP(int XP) const;

	/* Returns the current level this character is. Default is 1. */
	int GetCurrentLevel_Implementation() const;

	/* Returns the current amount of XP this character has. */
	float GetCurrentXP_Implementation() const;

	/* Returns the current XP progress normalized between 0.0 (just leveled up) and 1.0 (ready to level up). */
	float GetXPProgressNormalized_Implementation() const;
	//~ End of AuraExperience Interface

private:
	/* Levels infos defined for this character. */
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UDataAsset_LevelUpInfo> LevelUpInfo;
};
