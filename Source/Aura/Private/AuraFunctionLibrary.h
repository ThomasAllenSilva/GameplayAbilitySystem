// Thomas Learning Project

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "AuraFunctionLibrary.generated.h"

struct FGameplayTag;
class UAbilitySystemComponent;

/**
 * Common functions used by throughout this project
 */
UCLASS()
class UAuraFunctionLibrary final : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	/* Retrieves the XP reward for an enemy using its tag and level */
	static int GetXPRewardForEnemy(const UObject* WorldContextObject, const FGameplayTag& EnemyTag, const int EnemyLevel);

	/* Get the cursor location in the nearest object point in the mouse direction */
	UFUNCTION(BlueprintCallable, meta = (DefaultToSelf = "WorldContextObject"))
	static FVector GetCursorWorldLocation(const UObject* WorldContextObject);

	UFUNCTION(BlueprintCallable, meta = (DefaultToSelf = "WorldContextObject"))
	static void UpgradeAttribute(UAbilitySystemComponent* AbilitySystemComponent, const FGameplayAttribute Attribute, const float UpgradeMagnitude = 1);
};
