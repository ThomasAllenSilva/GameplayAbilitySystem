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

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	/* Gets the current level this character is. Default is 1. */
	int GetCurrentLevel() const;
};
