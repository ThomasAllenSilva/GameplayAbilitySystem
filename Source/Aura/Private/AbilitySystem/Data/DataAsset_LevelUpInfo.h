// Thomas Learning Project

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DataAsset_LevelUpInfo.generated.h"

USTRUCT()
struct FLevelUpInfo final : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	int XPRequirement;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	int AttributePointAward = 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	int AbilityPointAward = 1;
};

/**
 *
 */
UCLASS()
class UDataAsset_LevelUpInfo final : public UDataAsset
{
	GENERATED_BODY()

public:
	/* Returns the level that it should be based on the XP param. */
	int FindLevelForXP(int InXP) const;
	
	int GetMaxLevel() const { return LevelsInfo.Num(); }

	int GetMaxLevelXPRequirement() const;

	FLevelUpInfo GetInformationForLevel(int LevelIndex) const;

private:
	UPROPERTY(EditDefaultsOnly)
	TArray<FLevelUpInfo> LevelsInfo;
};
