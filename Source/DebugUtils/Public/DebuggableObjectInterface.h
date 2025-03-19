// Thomas Learning Project

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "DebuggableObjectInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UDebuggableObjectInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * Component Used To Display Debug Info From UObjects
 */
class DEBUGUTILS_API IDebuggableObjectInterface
{
	GENERATED_BODY()

public:
	virtual void DisplayDebugInfo_Internal(const UObject* ContextObject) const;

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void DisplayDebugInfo() const;
};
