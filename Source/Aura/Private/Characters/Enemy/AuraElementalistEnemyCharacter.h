// Thomas Learning Project

#pragma once

#include "CoreMinimal.h"
#include "Characters/Enemy/AuraEnemyCharacter.h"
#include "AuraElementalistEnemyCharacter.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class AAuraElementalistEnemyCharacter final : public AAuraEnemyCharacter
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable)
	void IncrementMinionsCount(int Amount);

	UFUNCTION(BlueprintCallable)
	void DecrementMinionsCount(int Amount);

	UFUNCTION(BlueprintCallable)
	int GetCurrentMinionsCount() const;

	UFUNCTION(BlueprintCallable)
	int GetTargetMinionsCount() const;

	UFUNCTION(BlueprintCallable)
	bool ShouldSpawnNewMinions() const;

	UFUNCTION(BlueprintCallable)
	bool CanSpawnNewMinion() const;

private:
	UPROPERTY(EditDefaultsOnly)
	int MinMinionsCount;

	UPROPERTY(EditDefaultsOnly)
	int TargetMinionsCount;

	int CurrentMinionsCount;
};
