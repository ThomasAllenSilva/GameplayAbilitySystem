// Thomas Learning Project


#include "AuraGameInstance.h"

UAuraGameInstance::UAuraGameInstance()
{
	UE_LOG(LogTemp, Display, TEXT("Trying To Change"));
}

void UAuraGameInstance::StartGameInstance()
{
	Super::StartGameInstance();

	OnBeforeStartGameInstance();
}
