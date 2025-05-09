// Thomas Learning Project

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "AuraExperienceInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UAuraExperienceInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class IAuraExperienceInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	/* Returns the current level that this character should be based on the XP param. */
	virtual int GetLevelForXP(int XP) const = 0;

	/* Returns the current level this character is. Default is 1. */
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	int GetCurrentLevel() const;

	/* Returns the current amount of XP this character has. */
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	float GetCurrentXP() const;

	/* Returns the current XP progress normalized between 0.0 (just leveled up) and 1.0 (ready to level up). */
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	float GetXPProgressNormalized() const;
};
