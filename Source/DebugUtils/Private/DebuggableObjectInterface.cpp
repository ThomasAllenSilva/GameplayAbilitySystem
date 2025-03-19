// Thomas Learning Project

#include "DebuggableObjectInterface.h"

// Add default functionality here for any IDebuggableObjectInterface functions that are not pure virtual.

void IDebuggableObjectInterface::DisplayDebugInfo_Internal(const UObject* ContextObject) const
{
	Execute_DisplayDebugInfo(ContextObject);
}
