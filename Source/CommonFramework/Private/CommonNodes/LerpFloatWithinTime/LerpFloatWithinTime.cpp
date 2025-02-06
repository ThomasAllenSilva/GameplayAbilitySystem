// Thomas Learning Project

#include "LerpFloatWithinTime.h"

#include "TickableObject.h"

ULerpFloatWithinTime* ULerpFloatWithinTime::LerpFloatWithinTime(float A, float B, float Time)
{
	ULerpFloatWithinTime* Node = NewObject<ULerpFloatWithinTime>();

	Node->LerpA = A;

	Node->LerpB = B;

	Node->MaxTime = Time;

	return Node;
}

void ULerpFloatWithinTime::Activate()
{
	TickObject = NewObject<UTickableObject>();

	TickObject->OnTick.BindUObject(this, &ULerpFloatWithinTime::OnTick);

	ElapsedTime = 0.0f;
}

void ULerpFloatWithinTime::OnTick(float DeltaSeconds)
{
	ElapsedTime += DeltaSeconds;

	float alpha = FMath::Clamp(ElapsedTime / MaxTime, 0.0f, 1.0f);

	float value = FMath::Lerp(LerpA, LerpB, alpha);

	Tick.Broadcast(value);

	if (ElapsedTime >= MaxTime)
	{
		TickObject->OnTick.Unbind();

		TickObject = nullptr;

		Completed.Broadcast(value);
	}
}
