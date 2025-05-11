// Thomas Learning Project

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "DataAsset_AbilityInfo.generated.h"

class UMaterialInstance;
class UTexture2D;

USTRUCT(BlueprintType)
struct FAuraAbilityInfo
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FGameplayTag AbilityTag = FGameplayTag();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FGameplayTag CooldownTag = FGameplayTag();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TObjectPtr<const UTexture2D> AbilityIcon;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TObjectPtr<const UMaterialInstance> BackgroundMaterial;
};

/**
 * Contains an array of ability infos and helper methods
 */
UCLASS()
class UDataAsset_AbilityInfo final : public UDataAsset
{
	GENERATED_BODY()
	
public:
	FAuraAbilityInfo GetAbilityInfoByTag(const FGameplayTag& AbilityTag) const;

private:
	UPROPERTY(EditDefaultsOnly)
	TArray<FAuraAbilityInfo> AbilityInfo;
};
