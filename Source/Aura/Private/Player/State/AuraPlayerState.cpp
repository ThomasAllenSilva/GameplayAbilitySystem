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

float AAuraPlayerState::GetCurrentXP_Implementation() const
{
	bool bFound = false;

	float Level = AbilitySystemComponent->GetGameplayAttributeValue(UAuraExperienceAttributeSet::GetXPAttribute(), bFound);

	check(bFound);

	return Level;
}

float AAuraPlayerState::GetXPProgressNormalized_Implementation() const
{
	const int CurrentLevel = GetCurrentLevel_Implementation();

	const FLevelUpInfo LevelInfo = LevelUpInfo->GetInformationForLevel(CurrentLevel);

	const float XPRequirement = LevelInfo.XPRequirement;

	float CurrentXP = GetCurrentXP_Implementation();

	CurrentXP = FMath::Clamp(CurrentXP, 0.0f, LevelUpInfo->GetMaxLevelXPRequirement());

	return CurrentXP / XPRequirement;
}
