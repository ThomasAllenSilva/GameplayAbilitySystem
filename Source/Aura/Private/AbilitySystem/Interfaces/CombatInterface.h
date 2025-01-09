// Thomas Learning Project

#pragma once

#include "CoreMinimal.h"

#include "UObject/Interface.h"

#include "CombatInterface.generated.h"

static const FName ProjectileSocketName = TEXT("ProjectileSpawnPoint");

static const FName WarpName = TEXT("FacingTarget");

UINTERFACE(MinimalAPI, NotBlueprintable)
class UCombatInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class ICombatInterface
{
	GENERATED_BODY()

public:
	virtual FVector GetProjectileSpawnLocation() = 0;

	UFUNCTION(BlueprintCallable)
	virtual void UpdateWarpTargetFromLocation(const FVector& Location) = 0;
};
