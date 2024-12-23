// Thomas Learning Project

#pragma once

#include "CoreMinimal.h"
#include "Abilities/Tasks/AbilityTask.h"
#include "AbilityTask_GetCursorLocation.generated.h"
/**
 *	Probably not the best use of AbilityTask, but hey I'm learning ^^
 */

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FReceivedInputSignature, FVector, WorldLocation);

UCLASS()
class UAbilityTask_GetCursorLocation : public UAbilityTask
{
	GENERATED_BODY()
	
	UPROPERTY(BlueprintAssignable)
	FReceivedInputSignature	ReceivedInput;

	UFUNCTION(BlueprintCallable, meta = (HidePin = "OwningAbility", DefaultToSelf = "OwningAbility", BlueprintInternalUseOnly = "true"), Category = "Ability|Tasks")
	static UAbilityTask_GetCursorLocation* GetCursorLocation(UGameplayAbility* OwningAbility);

	virtual void Activate() override;
};
