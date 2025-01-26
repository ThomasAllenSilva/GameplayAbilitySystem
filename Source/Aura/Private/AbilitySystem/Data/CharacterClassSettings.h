// Thomas Learning Project

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "CharacterClassSettings.generated.h"

class UGameplayAbility;

class UGameplayEffect;

class UAttributeSet;

UCLASS()
class UCharacterClassSettings final : public UDataAsset
{
	GENERATED_BODY()

public:
	FORCEINLINE const TArray<TSubclassOf<UGameplayEffect>>& GetStartupEffects() const { return StartupEffects; }

	FORCEINLINE const TArray<TSubclassOf<UGameplayAbility>>& GetStartupAbilities() const { return StartupAbilities; }

	FORCEINLINE const TArray<TSubclassOf<UAttributeSet>>& GetStartupAttributes() const { return StartupAttributes; }

	FORCEINLINE const TArray<TObjectPtr<UCharacterClassSettings>>& GetSharedConfigurations() const { return SharedConfigurations; }

private:
	UPROPERTY(EditDefaultsOnly, Category = "Class Configuration")
	TArray<TSubclassOf<UGameplayEffect>> StartupEffects;

	UPROPERTY(EditDefaultsOnly, Category = "Class Configuration")
	TArray<TSubclassOf<UGameplayAbility>> StartupAbilities;

	UPROPERTY(EditDefaultsOnly, Category = "Class Configuration")
	TArray<TSubclassOf<UAttributeSet>> StartupAttributes;

	/*Settings that are also initialized with this class. Be careful with circular references which will cause stack overflow when initializing*/
	UPROPERTY(EditDefaultsOnly, Category = "Class Configuration")
	TArray<TObjectPtr<UCharacterClassSettings>> SharedConfigurations;
};
