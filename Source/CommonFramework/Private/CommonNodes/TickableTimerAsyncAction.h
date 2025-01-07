// Thomas Learning Project

#pragma once

#include "CoreMinimal.h"

#include "Kismet/BlueprintAsyncActionBase.h"

#include "TickableTimerAsyncAction.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FBPNodeOutputPin, float, DeltaSeconds);

UCLASS()
class UTickableTimerAsyncAction final : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable)
	FBPNodeOutputPin Tick;

	UPROPERTY(BlueprintAssignable)
	FBPNodeOutputPin Completed;

public:
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject", HidePin = "WorldContextObj", DefaultToSelf = "WorldContextObj"), Category = "AsyncNode")
	static UTickableTimerAsyncAction* TickableTimer(const UObject* WorldContextObj, float Time, float Rate);

	virtual void Activate() override;

private:
	FTimerHandle TimerHandle;

	bool bActive;

	const UObject* WorldContext;

	float MaxTime;

	float Rate;

	float ElapsedTime;

private:
	UFUNCTION()
	void InternalTick();

	UFUNCTION()
	void InternalCompleted();
};
