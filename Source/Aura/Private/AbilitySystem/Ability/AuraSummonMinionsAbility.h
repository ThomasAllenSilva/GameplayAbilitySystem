// Thomas Learning Project

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Ability/Base/AuraGameplayAbility.h"
#include "AuraSummonMinionsAbility.generated.h"

class AAuraElementalistEnemyCharacter;

/**
 *
 */
UCLASS(Abstract)
class UAuraSummonMinionsAbility final : public UAuraGameplayAbility
{
	GENERATED_BODY()

protected:
	virtual void OnGiveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec) override;

	UFUNCTION(BlueprintCallable)
	TArray<FVector> GetSpawnLocations() const;

	UFUNCTION(BlueprintCallable)
	APawn* SpawnRandomMinion(const FTransform& SpawnTransform);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Aura|Ability")
	AAuraElementalistEnemyCharacter* GetElementalistEnemyCharacterFromActorInfo() const;

private:
	UPROPERTY(EditDefaultsOnly, meta = (AllowPrivateAccess))
	float SpreadAngle = 90.0f;

	UPROPERTY(EditDefaultsOnly, meta = (AllowPrivateAccess))
	int MinionsCount = 5;

	UPROPERTY(EditDefaultsOnly, meta = (AllowPrivateAccess))
	float MinSpawnDistance = 150.0f;

	UPROPERTY(EditDefaultsOnly, meta = (AllowPrivateAccess))
	float MaxSpawnDistance = 400.0f;

	UPROPERTY(EditDefaultsOnly, meta = (AllowPrivateAccess))
	TArray<TSubclassOf<APawn>> Minions;

	/** The Elementalist Enemy Character that owns this ability */
	UPROPERTY()
	TWeakObjectPtr<AAuraElementalistEnemyCharacter>	OwnerElementalistEnemyCharacter;
};
