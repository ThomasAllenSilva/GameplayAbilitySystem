// Thomas Learning Project

#include "AuraBlueprintFunctionLibrary.h"

#include "GameFramework/PlayerState.h"

#include "AbilitySystem/Component/AuraAbilitySystemComponent.h"

#include "Player/State/AuraPlayerState.h"

#include "Player/Data/Gas/PlayerGasData.h"

#include "GameFeaturesSubsystem.h"

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
		UE_LOG(LogTemp, Warning, TEXT("Cannot Retrieve AbilitySystemComponent From Null Player State"));

		return nullptr;
	}

	AAuraPlayerState* AuraPlayerState = Cast<AAuraPlayerState>(PlayerState);

	UPlayerGasData* PlayerGasData = AuraPlayerState->GetPlayerGasData();

	return PlayerGasData->GetAbilitySystemComponent();
}

const UAuraAttributeSet* UAuraBlueprintFunctionLibrary::GetLocalPlayerAttributeSet(const UObject* WorldContextObject)
{
	AAuraPlayerState* PlayerState = Cast<AAuraPlayerState>(GetLocalPlayerState(WorldContextObject));

	checkf(PlayerState, TEXT("Cannot Retrieve AttributeSet From Null Player State"));

	UPlayerGasData* PlayerGasData = PlayerState->GetPlayerGasData();

	return PlayerGasData->GetAttributeSet();
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
