// Thomas Learning Project

#pragma once

#include "CoreMinimal.h"

#include "Engine/DataAsset.h"

#include "GameplayTagContainer.h"

#include "GlobalCharacterClassSettings.generated.h"

class UGameplayEffect;

class UGameplayAbility;

USTRUCT()
struct FClassSettings
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly)
	TArray<TSubclassOf<UGameplayEffect>> StartupEffects;

	UPROPERTY(EditDefaultsOnly)
	TArray<TSubclassOf<UGameplayAbility>> StartupAbilities;
};

UCLASS()
class UGlobalCharacterClassSettings final : public UDataAsset
{
	GENERATED_BODY()

public:
	FORCEINLINE const TArray<TSubclassOf<UGameplayEffect>>& GetStartupEffects() const { return StartupEffects; }

	FORCEINLINE const TArray<TSubclassOf<UGameplayAbility>>& GetStartupAbilities() const { return StartupAbilities; }

	FORCEINLINE const FClassSettings* GetClassSettings(const FGameplayTag& ClassTag) const { return ClassSettings.Find(ClassTag); }

private:
	UPROPERTY(EditDefaultsOnly, Category = "Shared Configuration")
	TArray<TSubclassOf<UGameplayEffect>> StartupEffects;

	UPROPERTY(EditDefaultsOnly, Category = "Shared Configuration")
	TArray<TSubclassOf<UGameplayAbility>> StartupAbilities;

	UPROPERTY(EditDefaultsOnly, Category = "Class Configuration")
	TMap<FGameplayTag, FClassSettings> ClassSettings;
};
