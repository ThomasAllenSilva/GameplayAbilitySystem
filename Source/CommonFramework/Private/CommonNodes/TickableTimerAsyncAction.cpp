// Thomas Learning Project

#include "CommonNodes/TickableTimerAsyncAction.h"

UTickableTimerAsyncAction* UTickableTimerAsyncAction::TickableTimer(const UObject* WorldContextObj, float Time, float Rate)
{
	UTickableTimerAsyncAction* Node = NewObject<UTickableTimerAsyncAction>();

	Node->WorldContext = WorldContextObj;

	Node->MaxTime = Time;

	Node->Rate = Rate;

	return Node;
}

void UTickableTimerAsyncAction::Activate()
{
	if (bActive)
	{
		return;
	}

	bActive = true;

	FTimerDelegate TimerDelegate;

	TimerDelegate.BindUObject(this, &UTickableTimerAsyncAction::InternalTick);

	WorldContext->GetWorld()->GetTimerManager().SetTimer(TimerHandle, TimerDelegate, Rate, true);
}

void UTickableTimerAsyncAction::InternalTick()
{
	float DeltaSeconds = WorldContext->GetWorld()->GetDeltaSeconds();

	ElapsedTime += DeltaSeconds;

	Tick.Broadcast(DeltaSeconds);

	if (DeltaSeconds >= MaxTime)
	{
		InternalCompleted();
	}
}

void UTickableTimerAsyncAction::InternalCompleted()
{
	WorldContext->GetWorld()->GetTimerManager().ClearTimer(TimerHandle);

	TimerHandle.Invalidate();

	float DeltaSeconds = WorldContext->GetWorld()->GetDeltaSeconds();

	Completed.Broadcast(DeltaSeconds);

	bActive = false;
}
