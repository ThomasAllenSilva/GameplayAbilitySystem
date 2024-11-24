// Thomas Learning Project


#include "AuraGameInstance.h"

void UAuraGameInstance::StartGameInstance()
{
	Super::StartGameInstance();

	UE_LOG(LogTemp, Display, TEXT("StartGameInstance"));

	OnBeforeStartGameInstance();
}
