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

private:
	int MinionsCount;
};
