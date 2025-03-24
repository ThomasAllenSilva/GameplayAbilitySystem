// Thomas Hero Project

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "DataAsset_CommonAbilitySet.generated.h"

class UCommonGameplayAbility;
class UGameplayEffect;
class UAttributeSet;
class UCommonAbilitySystemComponent;

/**
 *	Data used by the ability set to grant gameplay abilities.
 */
USTRUCT(BlueprintType)
struct FCommonAbilitySet_GameplayAbility
{
	GENERATED_BODY()

public:

	// Gameplay ability to grant.
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UCommonGameplayAbility> Ability = nullptr;

	// Level of ability to grant.
	UPROPERTY(EditDefaultsOnly)
	int32 AbilityLevel = 1;

	// Tag used to process input for the ability.
	UPROPERTY(EditDefaultsOnly, Meta = (Categories = "InputTag"))
	FGameplayTag InputTag;
};

/**
 *	Data used by the ability set to grant gameplay effects.
 */
USTRUCT(BlueprintType)
struct FCommonAbilitySet_GameplayEffect
{
	GENERATED_BODY()

public:

	// Gameplay effect to grant.
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UGameplayEffect> GameplayEffect = nullptr;

	// Level of gameplay effect to grant.
	UPROPERTY(EditDefaultsOnly)
	float EffectLevel = 1.0f;
};


/**
 *
 */
UCLASS()
class COMMONABILITYSYSTEM_API UDataAsset_CommonAbilitySet final : public UDataAsset
{
	GENERATED_BODY()

public:

	// Grants the ability set to the specified ability system component.
	void GiveToAbilitySystem(UCommonAbilitySystemComponent* InASC) const;

	void GiveAttributeSetsToAbilitySystem(UCommonAbilitySystemComponent* InASC) const;

private:
	// Gameplay abilities to grant when this ability set is granted.
	UPROPERTY(EditDefaultsOnly, Category = "Gameplay Abilities", meta = (TitleProperty = Ability))
	TArray<FCommonAbilitySet_GameplayAbility> GrantedGameplayAbilities;

	// Gameplay effects to grant when this ability set is granted.
	UPROPERTY(EditDefaultsOnly, Category = "Gameplay Effects", meta = (TitleProperty = GameplayEffect))
	TArray<FCommonAbilitySet_GameplayEffect> GrantedGameplayEffects;

	// Attribute sets to grant when this ability set is granted.
	UPROPERTY(EditDefaultsOnly, Category = "Attribute Sets", meta = (TitleProperty = AttributeSet))
	TArray<TSubclassOf<UAttributeSet>> GrantedAttributes;
};
