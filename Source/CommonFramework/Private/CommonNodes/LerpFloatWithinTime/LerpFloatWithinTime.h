// Thomas Learning Project

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "LerpFloatWithinTime.generated.h"

class UTickableObject;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FNodeOutputPin, float, LerpValue);

UCLASS()
class ULerpFloatWithinTime final : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "AsyncNode")
	static ULerpFloatWithinTime* LerpFloatWithinTime(float A, float B, float Time);

	virtual void Activate() override;

	UPROPERTY(BlueprintAssignable)
	FNodeOutputPin Tick;

	UPROPERTY(BlueprintAssignable)
	FNodeOutputPin Completed;

private:
	float LerpA;

	float LerpB;

	float ElapsedTime;

	float MaxTime;

	UTickableObject* TickObject = nullptr;

private:
	void OnTick(float DeltaSeconds);
};
