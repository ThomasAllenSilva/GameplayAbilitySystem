// Thomas Learning Project

#pragma once

#include "CoreMinimal.h"
#include "PlayerState/CommonAbilityPlayerState.h"
#include "AbilitySystem/Interfaces/AuraExperienceInterface.h"

#include "AuraPlayerState.generated.h"

class UDataAsset_LevelUpInfo;

/**
 * 
 */
UCLASS()
class AAuraPlayerState final : public ACommonAbilityPlayerState, public IAuraExperienceInterface
{
	GENERATED_BODY()
	
public:
	UDataAsset_LevelUpInfo* GetLevelUpInfo() const;

	//~ Begin AuraExperience Interface
	virtual int GetLevelForXP(int XP) const;

	virtual int GetCurrentLevel_Implementation() const;
	//~ End of AuraExperience Interface

private:
	UPROPERTY(EditDefaultsOnly)
	UDataAsset_LevelUpInfo* LevelUpInfo;
};
