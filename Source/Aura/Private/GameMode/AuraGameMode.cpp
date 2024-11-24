// Thomas Learning Project


#include "GameMode/AuraGameMode.h"

void AAuraGameMode::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage)
{
	Super::InitGame(MapName, Options, ErrorMessage);
	OnInitGame();
}
