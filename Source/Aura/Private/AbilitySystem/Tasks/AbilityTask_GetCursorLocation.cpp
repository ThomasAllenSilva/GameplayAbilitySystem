// Thomas Learning Project


#include "AbilitySystem/Tasks/AbilityTask_GetCursorLocation.h"

#include "AuraBlueprintFunctionLibrary.h"

UAbilityTask_GetCursorLocation* UAbilityTask_GetCursorLocation::GetCursorLocation(UGameplayAbility* OwningAbility)
{
	UAbilityTask_GetCursorLocation* Task = NewAbilityTask<UAbilityTask_GetCursorLocation>(OwningAbility);

	return Task;
}

void UAbilityTask_GetCursorLocation::Activate()
{
	const APlayerController* PlayerController = UAuraBlueprintFunctionLibrary::GetLocalPlayerController(this);

	FVector WorldLocation;

	FVector WorldDirection;

	PlayerController->DeprojectMousePositionToWorld(WorldLocation, WorldDirection);

	FHitResult HitResult;

	const FVector TraceEnd = (WorldDirection * FLT_MAX);

	GetWorld()->LineTraceSingleByChannel(HitResult, WorldLocation, TraceEnd, ECollisionChannel::ECC_Visibility);

	if (ShouldBroadcastAbilityTaskDelegates())
	{
		ReceivedInput.Broadcast(HitResult.ImpactPoint);
	}
}

