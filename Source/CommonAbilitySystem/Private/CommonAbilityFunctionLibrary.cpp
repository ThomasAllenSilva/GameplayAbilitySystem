// Thomas Hero Project


#include "CommonAbilityFunctionLibrary.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "Components/CommonAbilitySystemComponent.h"
#include "PlayerState/CommonAbilityPlayerState.h"
#include "PlayerController/CommonAbilityPlayerController.h"

APlayerController* UCommonAbilityFunctionLibrary::GetLocalPlayerController(const UObject* WorldContextObject)
{
	checkf(WorldContextObject, TEXT("Context Object Is Required To Retrieve Local Player Controller"));

	UWorld* World = WorldContextObject->GetWorld();
	if (World == nullptr) return nullptr;

	ULocalPlayer* LocalPlayer = World->GetFirstLocalPlayerFromController();
	if (LocalPlayer == nullptr) return nullptr;

	APlayerController* PlayerController = LocalPlayer->GetPlayerController(World);

	check(PlayerController);

	return PlayerController;
}

APlayerState* UCommonAbilityFunctionLibrary::GetLocalPlayerState(const UObject* WorldContextObject)
{
	checkf(WorldContextObject, TEXT("Context Object Is Required To Retrieve Local Player State"));

	APlayerController* PlayerController = GetLocalPlayerController(WorldContextObject);

	if (PlayerController == nullptr)
	{
		return nullptr;
	}

	APlayerState* PlayerState = PlayerController->GetPlayerState<APlayerState>();

	check(PlayerState);

	return PlayerState;
}

ACommonAbilityPlayerState* UCommonAbilityFunctionLibrary::GetLocalCommonAbilityPlayerState(const UObject* WorldContextObject)
{
	ACommonAbilityPlayerState* PlayerState = Cast<ACommonAbilityPlayerState>(GetLocalPlayerState(WorldContextObject));

	return PlayerState;
}

ACommonAbilityPlayerController* UCommonAbilityFunctionLibrary::GetLocalCommonAbilityPlayerController(const UObject* WorldContextObject)
{
	ACommonAbilityPlayerController* PlayerController = Cast<ACommonAbilityPlayerController>(GetLocalPlayerController(WorldContextObject));

	check(PlayerController);

	return PlayerController;
}

UCommonAbilitySystemComponent* UCommonAbilityFunctionLibrary::GetLocalPlayerAbilitySystemComponent(const UObject* WorldContextObject)
{
	ACommonAbilityPlayerState* PlayerState = GetLocalCommonAbilityPlayerState(WorldContextObject);

	if (PlayerState == nullptr)
	{
		return nullptr;
	}

	return Cast<UCommonAbilitySystemComponent>(PlayerState->GetAbilitySystemComponent());
}

void UCommonAbilityFunctionLibrary::AddGameplayTagToActorIfNone(AActor* Actor, const FGameplayTag& Tag)
{
	UAbilitySystemComponent* ASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(Actor);

	if (ASC->HasMatchingGameplayTag(Tag) == false)
	{
		ASC->AddLooseGameplayTag(Tag);
	}
}
