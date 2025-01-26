// Thomas Learning Project

#include "AuraBlueprintFunctionLibrary.h"

#include "GameFramework/PlayerState.h"

#include "AbilitySystem/Component/AuraAbilitySystemComponent.h"

#include "Player/State/AuraPlayerState.h"

#include "Kismet/GameplayStatics.h"

#include "GameFeaturesSubsystem.h"

#include "AbilitySystemBlueprintLibrary.h"

#include "AbilitySystem/Ability/AuraGameplayAbility.h"

APlayerState* UAuraBlueprintFunctionLibrary::GetLocalPlayerState(const UObject* WorldContextObject)
{
	checkf(WorldContextObject, TEXT("Context Object Is Required To Get Player State"));

	UWorld* World = WorldContextObject->GetWorld();
	if (World == nullptr) return nullptr;

	ULocalPlayer* LocalPlayer = World->GetFirstLocalPlayerFromController();
	if (LocalPlayer == nullptr) return nullptr;

	APlayerController* PlayerController = LocalPlayer->GetPlayerController(World);
	if (PlayerController == nullptr) return nullptr;

	return PlayerController->GetPlayerState<APlayerState>();
}

UAuraAbilitySystemComponent* UAuraBlueprintFunctionLibrary::GetLocalPlayerAbilitySystemComponent(const UObject* WorldContextObject)
{
	APlayerState* PlayerState = GetLocalPlayerState(WorldContextObject);

	if (PlayerState == nullptr)
	{
		return nullptr;
	}

	AAuraPlayerState* AuraPlayerState = Cast<AAuraPlayerState>(PlayerState);

	return Cast<UAuraAbilitySystemComponent>(AuraPlayerState->GetAbilitySystemComponent());
}

const APlayerController* UAuraBlueprintFunctionLibrary::GetLocalPlayerController(const UObject* WorldContextObject)
{
	UWorld* World = WorldContextObject->GetWorld();
	if (World == nullptr) return nullptr;

	ULocalPlayer* LocalPlayer = World->GetFirstLocalPlayerFromController();
	if (LocalPlayer == nullptr) return nullptr;

	APlayerController* PlayerController = LocalPlayer->GetPlayerController(World);

	return PlayerController;
}

const FString UAuraBlueprintFunctionLibrary::GetTagLastName(const FGameplayTag& Tag)
{
	if (!Tag.IsValid())
	{
		return FString("Invalid Or Null Tag");
	}

	FString TagString = Tag.ToString();

	int32 LastDotIndex;

	if (TagString.FindLastChar('.', LastDotIndex))
	{
		FString LastName = TagString.Mid(LastDotIndex + 1);

		FString FormattedName;

		for (int32 i = 0; i < LastName.Len(); i++)
		{
			if (i > 0 && FChar::IsUpper(LastName[i]) && FChar::IsLower(LastName[i - 1]))
			{
				FormattedName.AppendChar(' ');
			}

			FormattedName.AppendChar(LastName[i]);
		}

		return FormattedName;
	}

	return TagString;
}

void UAuraBlueprintFunctionLibrary::AddGameplayTagToActorIfNone(AActor* Actor, const FGameplayTag& Tag)
{
	UAbilitySystemComponent* ASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(Actor);

	if (ASC->HasMatchingGameplayTag(Tag) == false)
	{
		ASC->AddLooseGameplayTag(Tag);
	}
}

void UAuraBlueprintFunctionLibrary::LoadAndActivateGameFeature(const FString& PluginName)
{
	UGameFeaturesSubsystem& GameFeaturesSubsystem = UGameFeaturesSubsystem::Get();

	FString OutPluginName;

	GameFeaturesSubsystem.GetPluginURLByName(PluginName, OutPluginName);

	GameFeaturesSubsystem.LoadAndActivateGameFeaturePlugin(
		OutPluginName,
		FGameFeaturePluginLoadComplete::CreateLambda([](const UE::GameFeatures::FResult& Result)
			{
				if (Result.HasError())
				{
					UE_LOG(LogTemp, Error, TEXT("Failed to load and activate Game Feature Plugin"));
				}
				else
				{
					UE_LOG(LogTemp, Log, TEXT("Game Feature Plugin successfully loaded and activated."));
				}
			})
	);
}

void UAuraBlueprintFunctionLibrary::UnloadGameFeature(const FString& PluginName)
{
	UGameFeaturesSubsystem& GameFeaturesSubsystem = UGameFeaturesSubsystem::Get();

	FString OutPluginName;

	GameFeaturesSubsystem.GetPluginURLByName(PluginName, OutPluginName);

	GameFeaturesSubsystem.UnloadGameFeaturePlugin(
		OutPluginName,
		FGameFeaturePluginLoadComplete::CreateLambda([](const UE::GameFeatures::FResult& Result)
			{
				if (Result.HasError())
				{
					UE_LOG(LogTemp, Error, TEXT("Failed to load and activate Game Feature Plugin"));
				}
				else
				{
					UE_LOG(LogTemp, Log, TEXT("Game Feature Plugin successfully loaded and activated."));
				}
			})
		, true);
}
