// Thomas Learning Project

#include "TickableObject.h"

void UTickableObject::Tick(float DeltaTime)
{
	OnTick.ExecuteIfBound(DeltaTime);
}

TStatId UTickableObject::GetStatId() const
{
	RETURN_QUICK_DECLARE_CYCLE_STAT(UTickableTimerAsyncAction, STATGROUP_Tickables);
}
