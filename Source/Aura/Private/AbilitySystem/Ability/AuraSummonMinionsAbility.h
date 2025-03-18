// Thomas Learning Project

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Ability/Base/AuraGameplayAbility.h"
#include "AuraSummonMinionsAbility.generated.h"

/**
 * 
 */
UCLASS()
class UAuraSummonMinionsAbility final : public UAuraGameplayAbility
{
	GENERATED_BODY()
	
private:
	TArray<FVector> GetSpawnLocations() const;


private:
	UPROPERTY(EditDefaultsOnly, meta = (AllowPrivateAccess))
	float SpreadAngle;

	UPROPERTY(EditDefaultsOnly, meta = (AllowPrivateAccess))
	int MinionsCount;
};
