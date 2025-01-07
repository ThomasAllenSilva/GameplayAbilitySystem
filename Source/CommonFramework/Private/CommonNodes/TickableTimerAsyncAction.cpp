// Thomas Learning Project

#include "CommonNodes/TickableTimerAsyncAction.h"

UTickableTimerAsyncAction* UTickableTimerAsyncAction::TickableTimer(const UObject* WorldContextObj, float Time)
{
	UTickableTimerAsyncAction* Node = NewObject<UTickableTimerAsyncAction>();

	Node->WorldContext = WorldContextObj;

	Node->MaxTime = Time;

	return Node;
}

void UTickableTimerAsyncAction::Activate()
{
	if (bActive)
	{
		return;
	}

	bActive = true;
}

void UTickableTimerAsyncAction::Tick(float DeltaTime)
{
	//TODO: Fix this tick function because its prolly ticking at every tick group
	if (bActive)
	{
		ElapsedTime += DeltaTime;

		OnTick.Broadcast(DeltaTime);

		if (DeltaTime >= MaxTime)
		{
			InternalCompleted();
		}
	}

	UE_LOG(LogTemp, Display, TEXT("Ticking"));
}

void UTickableTimerAsyncAction::InternalCompleted()
{
	float DeltaSeconds = WorldContext->GetWorld()->GetDeltaSeconds();

	Completed.Broadcast(DeltaSeconds);

	bActive = false;
}

TStatId UTickableTimerAsyncAction::GetStatId() const
{
	RETURN_QUICK_DECLARE_CYCLE_STAT(UTickableTimerAsyncAction, STATGROUP_Tickables);
}
