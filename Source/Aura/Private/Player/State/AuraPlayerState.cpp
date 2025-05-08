// Thomas Learning Project


#include "Player/State/AuraPlayerState.h"
#include "AbilitySystem/Data/DataAsset_LevelUpInfo.h"
#include "AbilitySystem/AttributeSets/AuraExperienceAttributeSet.h"
#include "Components/CommonAbilitySystemComponent.h"

UDataAsset_LevelUpInfo* AAuraPlayerState::GetLevelUpInfo() const
{
	return LevelUpInfo;
}

int AAuraPlayerState::GetLevelForXP(int XP) const
{
	return LevelUpInfo->FindLevelForXP(XP);
}

int AAuraPlayerState::GetCurrentLevel_Implementation() const
{
	bool bFound = false;

	float Level = AbilitySystemComponent->GetGameplayAttributeValue(UAuraExperienceAttributeSet::GetLevelAttribute(), bFound);

	check(bFound);

	return Level;
}
