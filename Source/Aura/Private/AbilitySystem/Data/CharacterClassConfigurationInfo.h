// Thomas Learning Project

#pragma once

#include "CoreMinimal.h"

#include "Engine/DataAsset.h"

#include "GameplayTagContainer.h"

#include "CharacterClassConfigurationInfo.generated.h"

class UGameplayEffect;

USTRUCT()
struct FClassConfigurationInfo
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, Category = "Character Configuration")
	TSubclassOf<UGameplayEffect> PrimaryAttributesStartEffect;
};

UCLASS()
class UCharacterClassConfigurationInfo final : public UDataAsset
{
	GENERATED_BODY()

public:
	const FClassConfigurationInfo& GetClassConfiguration(const FGameplayTag& ClassTag) const;

	UPROPERTY(EditDefaultsOnly, Category = "Common Class Configuration")
	TSubclassOf<UGameplayEffect> SecondaryAttributesStartEffect;

	UPROPERTY(EditDefaultsOnly, Category = "Common Class Configuration")
	TSubclassOf<UGameplayEffect> VitalAttributesStartEffect;

private:
	UPROPERTY(EditDefaultsOnly, Category = "Class Configuration")
	TMap<FGameplayTag, FClassConfigurationInfo> ClassesConfigurations;
};
