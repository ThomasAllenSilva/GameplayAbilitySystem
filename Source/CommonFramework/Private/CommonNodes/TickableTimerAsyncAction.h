// Thomas Learning Project

#pragma once

#include "CoreMinimal.h"

#include "Kismet/BlueprintAsyncActionBase.h"

#include "TickableTimerAsyncAction.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FBPNodeOutputPin, float, DeltaSeconds);

UCLASS()
class UTickableTimerAsyncAction final : public UBlueprintAsyncActionBase, public FTickableGameObject
{
	GENERATED_BODY()

public:
	virtual void Tick(float DeltaTime) override;

	virtual TStatId GetStatId() const override;

	UPROPERTY(BlueprintAssignable)
	FBPNodeOutputPin OnTick;

	UPROPERTY(BlueprintAssignable)
	FBPNodeOutputPin Completed;

public:
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject", HidePin = "WorldContextObj", DefaultToSelf = "WorldContextObj"), Category = "AsyncNode")
	static UTickableTimerAsyncAction* TickableTimer(const UObject* WorldContextObj, float Time);

	virtual void Activate() override;

private:
	bool bActive;

	const UObject* WorldContext;

	float MaxTime;

	float ElapsedTime;

private:
	UFUNCTION()
	void InternalCompleted();
};
