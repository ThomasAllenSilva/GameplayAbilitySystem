// Thomas Learning Project

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "CharacterClassSettings.generated.h"

class UGameplayAbility;

class UGameplayEffect;

UCLASS()
class UCharacterClassSettings final : public UDataAsset
{
	GENERATED_BODY()

public:
	FORCEINLINE const TArray<TSubclassOf<UGameplayEffect>>& GetStartupEffects() const { return StartupEffects; }

	FORCEINLINE const TArray<TSubclassOf<UGameplayAbility>>& GetStartupAbilities() const { return StartupAbilities; }

private:
	UPROPERTY(EditDefaultsOnly, Category = "Class Configuration")
	TArray<TSubclassOf<UGameplayEffect>> StartupEffects;

	UPROPERTY(EditDefaultsOnly, Category = "Class Configuration")
	TArray<TSubclassOf<UGameplayAbility>> StartupAbilities;
};
