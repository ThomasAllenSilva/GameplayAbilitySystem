// Thomas Learning Project

#pragma once

#include "CoreMinimal.h"

#include "UObject/Interface.h"

#include "CombatInterface.generated.h"

#define PROJECTILE_SOCKET_NAME "ProjectileSpawnPoint"

UINTERFACE(MinimalAPI)
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
};
