// Thomas Learning Project


#include "AuraFunctionLibrary.h"
#include "GameMode/AuraGameMode.h"

int UAuraFunctionLibrary::GetXPRewardForEnemy(const UObject* WorldContextObject, const FGameplayTag& EnemyTag, const int EnemyLevel)
{
	UWorld* const World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull);

	checkf(World, TEXT("Cannot retrieve game mode from null world"));

	const AAuraGameMode* AuraGameMode = World->GetAuthGameMode<AAuraGameMode>();

	return AuraGameMode->GetXPRewardForEnemy(EnemyTag, EnemyLevel);
}
