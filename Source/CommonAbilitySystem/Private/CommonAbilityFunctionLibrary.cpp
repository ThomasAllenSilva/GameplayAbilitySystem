// Thomas Hero Project


#include "CommonAbilityFunctionLibrary.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "Components/CommonAbilitySystemComponent.h"
#include "PlayerState/CommonAbilityPlayerState.h"

ACommonAbilityPlayerState* UCommonAbilityFunctionLibrary::GetLocalPlayerState(const UObject* WorldContextObject)
{
	checkf(WorldContextObject, TEXT("Context Object Is Required To Get Player State"));

	UWorld* World = WorldContextObject->GetWorld();
	if (World == nullptr) return nullptr;

	ULocalPlayer* LocalPlayer = World->GetFirstLocalPlayerFromController();
	if (LocalPlayer == nullptr) return nullptr;

	APlayerController* PlayerController = LocalPlayer->GetPlayerController(World);
	if (PlayerController == nullptr) return nullptr;

	ACommonAbilityPlayerState* PlayerState = PlayerController->GetPlayerState<ACommonAbilityPlayerState>();

	check(PlayerState);

	return PlayerState;
}

UCommonAbilitySystemComponent* UCommonAbilityFunctionLibrary::GetLocalPlayerAbilitySystemComponent(const UObject* WorldContextObject)
{
	ACommonAbilityPlayerState* PlayerState = GetLocalPlayerState(WorldContextObject);

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
