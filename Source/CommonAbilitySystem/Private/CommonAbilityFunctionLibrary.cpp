// Thomas Hero Project


#include "CommonAbilityFunctionLibrary.h"
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

UCommonAbilitySystemComponent* UCommonAbilityFunctionLibrary::GetCommonAbilitySystemComponentFromActor(AActor* Actor)
{
	UAbilitySystemComponent* ASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(Actor);

	checkf(ASC, TEXT("Actor does not contain AbilitySystemComponent: %s"), *Actor->GetFName().ToString());

	return CastChecked<UCommonAbilitySystemComponent>(ASC);
}

UCommonAbilitySystemComponent* UCommonAbilityFunctionLibrary::GetCommonAbilitySystemComponentFromASC(UAbilitySystemComponent* AbilitySystemComponent)
{
	return CastChecked<UCommonAbilitySystemComponent>(AbilitySystemComponent);
}

float UCommonAbilityFunctionLibrary::GetMaximumEffectCooldownRemainingForTag(const FGameplayTag Tag, const UAbilitySystemComponent* ASC)
{
	FGameplayEffectQuery EffectQuery = FGameplayEffectQuery::MakeQuery_MatchAnyOwningTags(Tag.GetSingleTagContainer());

	TArray<float> ActiveEffectsTimeRemaining = ASC->GetActiveEffectsTimeRemaining(EffectQuery);

	checkf(ActiveEffectsTimeRemaining.Num() > 0, TEXT("Attempting to read an empty array"));

	float RemainingTime = ActiveEffectsTimeRemaining[0];

	for (int i = 0; i < ActiveEffectsTimeRemaining.Num(); i++)
	{
		if (ActiveEffectsTimeRemaining[i] > RemainingTime)
		{
			RemainingTime = ActiveEffectsTimeRemaining[i];
		}
	}

	return RemainingTime;
}

void UCommonAbilityFunctionLibrary::AddGameplayTagToActorIfNone(AActor* Actor, const FGameplayTag& Tag)
{
	UAbilitySystemComponent* ASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(Actor);

	check(ASC);

	if (ASC->HasMatchingGameplayTag(Tag) == false)
	{
		ASC->AddLooseGameplayTag(Tag);
	}
}

void UCommonAbilityFunctionLibrary::CompletelyRemoveGameplayTagFromActor(AActor* Actor, const FGameplayTag& Tag)
{
	UAbilitySystemComponent* ASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(Actor);

	check(ASC);

	int TagCount = ASC->GetTagCount(Tag);

	if (TagCount > 0)
	{
		ASC->RemoveLooseGameplayTag(Tag, TagCount);
	}
}

int UCommonAbilityFunctionLibrary::GetInt32Max()
{
	return INT32_MAX;
}

float UCommonAbilityFunctionLibrary::GetFloatBigNumber()
{
	return UE_BIG_NUMBER;
}

const FString UCommonAbilityFunctionLibrary::GetTagLastName(const FGameplayTag& Tag)
{
	if (!Tag.IsValid())
	{
		return FString("Invalid Tag");
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
