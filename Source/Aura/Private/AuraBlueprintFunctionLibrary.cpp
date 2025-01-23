// Thomas Learning Project

#include "AuraBlueprintFunctionLibrary.h"

#include "GameFramework/PlayerState.h"

#include "AbilitySystem/Component/AuraAbilitySystemComponent.h"

#include "Player/State/AuraPlayerState.h"

#include "Player/Data/Gas/PlayerGasData.h"

#include "GameMode/AuraGameMode.h"

#include "Kismet/GameplayStatics.h"

#include "AbilitySystem/Data/GlobalCharacterClassSettings.h"

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

AAuraGameMode* UAuraBlueprintFunctionLibrary::GetAuraGameMode(const UObject* WorldContextObject)
{
	AAuraGameMode* AuraGameMode = CastChecked<AAuraGameMode>(UGameplayStatics::GetGameMode(WorldContextObject));

	return AuraGameMode;
}

void UAuraBlueprintFunctionLibrary::InitializeGlobalCharacterClass(const UObject* WorldContextObject, const FGameplayTag& ClassTag, UAuraAbilitySystemComponent* ASC)
{
	AAuraGameMode* AuraGameMode = GetAuraGameMode(WorldContextObject);

	UGlobalCharacterClassSettings* CharacterClassConfigurationInfo = AuraGameMode->GetCharacterClassConfigurationInfo();

	checkf(CharacterClassConfigurationInfo, TEXT("Aura Game Mode Has An Invalid Or Null CharacterClassConfigurationInfo Data"));

	for (const TSubclassOf<UGameplayEffect>& GameplayEffect : CharacterClassConfigurationInfo->GetStartupEffects())
	{
		FGameplayEffectSpecHandle SpecHandle = ASC->MakeOutgoingSpec(GameplayEffect, 1, ASC->MakeEffectContext());

		ASC->ApplyGameplayEffectSpecToSelf(*SpecHandle.Data.Get());
	}

	for (const TSubclassOf<UGameplayAbility>& AbilityTemplate : CharacterClassConfigurationInfo->GetStartupAbilities())
	{
		FGameplayAbilitySpec AbilitySpec = FGameplayAbilitySpec(AbilityTemplate);

		if (const UAuraGameplayAbility* AuraGameplayAbility = Cast<UAuraGameplayAbility>(AbilitySpec.Ability))
		{
			AbilitySpec.DynamicAbilityTags.AddTag(AuraGameplayAbility->InputTag);
		}

		ASC->GiveAbility(AbilitySpec);
	}

	if (const FClassSettings* ClassSettings = CharacterClassConfigurationInfo->GetClassSettings(ClassTag))
	{
		for (const TSubclassOf<UGameplayEffect>& GameplayEffect : ClassSettings->StartupEffects)
		{
			FGameplayEffectSpecHandle SpecHandle = ASC->MakeOutgoingSpec(GameplayEffect, 1, ASC->MakeEffectContext());

			ASC->ApplyGameplayEffectSpecToSelf(*SpecHandle.Data.Get());
		}

		for (const TSubclassOf<UGameplayAbility>& AbilityTemplate : ClassSettings->StartupAbilities)
		{
			if (IsValid(AbilityTemplate) == false)
			{
				continue;
			}

			FGameplayAbilitySpec AbilitySpec = FGameplayAbilitySpec(AbilityTemplate);

			if (const UAuraGameplayAbility* AuraGameplayAbility = Cast<UAuraGameplayAbility>(AbilitySpec.Ability))
			{
				AbilitySpec.DynamicAbilityTags.AddTag(AuraGameplayAbility->InputTag);
			}

			ASC->GiveAbility(AbilitySpec);
		}
	}
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
