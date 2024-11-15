// Thomas Learning Project

#pragma once

#include "CoreMinimal.h"

#include "Engine/DataAsset.h"

#include "GameplayTagContainer.h"

#include "PickupMessagesDataAsset.generated.h"

USTRUCT()
struct FPickupMessageDefinition
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly)
	FName Message;

	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UTexture2D> Texture;
};

UCLASS()
class UPickupMessagesDataAsset final : public UDataAsset
{
	GENERATED_BODY()

public:
	const FPickupMessageDefinition& GetPickupMessageDefinition(const FGameplayTag& Tag);

private:
	UPROPERTY(EditDefaultsOnly)
	TMap<FGameplayTag, FPickupMessageDefinition> MessagesDefinitions;
};
