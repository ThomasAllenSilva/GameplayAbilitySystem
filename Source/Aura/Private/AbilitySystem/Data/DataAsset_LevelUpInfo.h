// Thomas Learning Project

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DataAsset_LevelUpInfo.generated.h"

/* Defines XP requirement and award points for level upgrades. */
USTRUCT()
struct FLevelInfo final : public FTableRowBase
{
	GENERATED_BODY()

	/* The amount of XP this level needs to be completed. */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	int XPRequirement;

	/* The amount of attribute points to award the player when he completes this level. This is used to upgrade attributes. */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	int AttributePointAward = 1;

	/* The amount of ability points to award the player when he completes this level. This is used to unlock abilities. */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	int AbilityPointAward = 1;
};

/**
 * Contains information about each level created and helper functions
 */
UCLASS()
class UDataAsset_LevelUpInfo final : public UDataAsset
{
	GENERATED_BODY()

public:
	/* Returns the level that it should be based on the XP param. */
	int FindLevelForXP(int InXP) const;
	
	/* Returns the max level count (example: Max Level = 100)*/
	int GetMaxLevel() const;

	/* Get the last level XP Requirement */
	int GetMaxLevelXPRequirement() const;

	/* Returns the information of the level in the specified index */
	const FLevelInfo& GetInformationForLevel(int LevelIndex) const;

private:
	/* Array containing information about each level created. NOTE: The 'real' level should start at 1 and the index 0 should be ignored. */
	UPROPERTY(EditDefaultsOnly)
	TArray<FLevelInfo> LevelsInfo;
};
