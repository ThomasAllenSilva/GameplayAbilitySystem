// Thomas Learning Project


#include "AuraFunctionLibrary.h"
#include "GameMode/AuraGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "CommonAbilityFunctionLibrary.h"

int UAuraFunctionLibrary::GetXPRewardForEnemy(const UObject* WorldContextObject, const FGameplayTag& EnemyTag, const int EnemyLevel)
{
	UWorld* const World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull);

	checkf(World, TEXT("Cannot retrieve game mode from null world"));

	const AAuraGameMode* AuraGameMode = World->GetAuthGameMode<AAuraGameMode>();

	return AuraGameMode->GetXPRewardForEnemy(EnemyTag, EnemyLevel);
}

FVector UAuraFunctionLibrary::GetCursorWorldLocation(const UObject* WorldContextObject)
{
	const UWorld* World = WorldContextObject->GetWorld();

	const ULocalPlayer* LocalPlayer = World->GetFirstLocalPlayerFromController();

	const APlayerController* PlayerController = LocalPlayer->GetPlayerController(World);

	FVector WorldLocation;
	FVector WorldDirection;

	PlayerController->DeprojectMousePositionToWorld(WorldLocation, WorldDirection);

	FHitResult HitResult;

	const FVector EndTraceLocation = ( WorldDirection) * UE_MAX_FLT;

	World->LineTraceSingleByChannel(HitResult, WorldLocation, EndTraceLocation, ECollisionChannel::ECC_Visibility);

	return HitResult.ImpactPoint;
}
