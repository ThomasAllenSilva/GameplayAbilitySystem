// Thomas Learning Project

#pragma once

#include "CoreMinimal.h"

#include "Engine/DataAsset.h"

#include "GameplayTagContainer.h"

#include "PickupMessagesDataAsset.generated.h"

USTRUCT(BlueprintType)
struct FPickupMessageDefinition
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FName Message;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TObjectPtr<UTexture2D> Texture;
};

UCLASS(BlueprintType)
class UPickupMessagesDataAsset final : public UDataAsset
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	const FPickupMessageDefinition& GetPickupMessageDefinition(const FGameplayTag& Tag);

private:
	UPROPERTY(EditDefaultsOnly)
	TMap<FGameplayTag, FPickupMessageDefinition> MessagesDefinitions;
};
