// Thomas Learning Project

#include "AuraBlueprintFunctionLibrary.h"

#include "GameFramework/PlayerState.h"

#include "AbilitySystem/Component/AuraAbilitySystemComponent.h"

#include "Player/State/AuraPlayerState.h"

#include "Player/Data/Gas/PlayerGasData.h"

APlayerState* UAuraBlueprintFunctionLibrary::GetLocalPlayerState(const UObject* WorldContextObject)
{
	checkf(WorldContextObject, TEXT("Context Object Is Required To Get Player State"));

	UWorld* World = WorldContextObject->GetWorld();

	ULocalPlayer* LocalPlayer = World->GetFirstLocalPlayerFromController();
	if (LocalPlayer == nullptr) return nullptr;

	APlayerController* PlayerController = LocalPlayer->GetPlayerController(World);
	if (PlayerController == nullptr) return nullptr;

	return PlayerController->GetPlayerState<APlayerState>();
}

UAuraAbilitySystemComponent* UAuraBlueprintFunctionLibrary::GetLocalPlayerAbilitySystemComponent(const UObject* WorldContextObject)
{
	AAuraPlayerState* PlayerState = Cast<AAuraPlayerState>(GetLocalPlayerState(WorldContextObject));

	UPlayerGasData* PlayerGasData = PlayerState->GetPlayerGasData();

	return PlayerGasData->GetAbilitySystemComponent();
}

const UAuraAttributeSet* UAuraBlueprintFunctionLibrary::GetLocalPlayerAttributeSet(const UObject* WorldContextObject)
{
	AAuraPlayerState* PlayerState = Cast<AAuraPlayerState>(GetLocalPlayerState(WorldContextObject));

	checkf(PlayerState, TEXT("Cannot Retrieve AttributeSet From Null Player State"));

	UPlayerGasData* PlayerGasData = PlayerState->GetPlayerGasData();

	return PlayerGasData->GetAttributeSet();
}
