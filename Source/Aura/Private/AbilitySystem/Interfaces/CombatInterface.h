// Thomas Learning Project

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "CombatInterface.generated.h"

static const FName WeaponSocketName = TEXT("TipSocket");

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
	UFUNCTION(BlueprintCallable)
	virtual FVector GetWeaponSocketLocation() = 0;

	UFUNCTION(BlueprintCallable)
	virtual void UpdateWarpTargetFromLocation(const FVector& Location) = 0;

	/* Sets the actor to be being aimed at or attacked */
	UFUNCTION(BlueprintCallable)
	virtual void SetTargetActor(AActor* InTargetActor) = 0;

	/*
	* Returns the current target actor
	* This may return null if no target is currently set or available.
	*/
	UFUNCTION(BlueprintCallable)
	virtual AActor* GetTargetActor() const = 0;

	/* Returns the current target actor. No failure allowed */
	UFUNCTION(BlueprintCallable)
	virtual AActor* GetTargetActorChecked() const = 0;

	/* Clears the current target actor */
	UFUNCTION(BlueprintCallable)
	virtual void ClearTargetActor() = 0;

};
