// Thomas Learning Project

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/LocalPlayerSubsystem.h"
#include "AuraAbilitySystemSubsystem.generated.h"

/**
 * 
 */

class UAuraAbilitySystemComponent;

UCLASS()
class UAuraAbilitySystemSubsystem final : public ULocalPlayerSubsystem
{
	GENERATED_BODY()

public:

	
public:
	UFUNCTION(BlueprintCallable)
	const UAuraAbilitySystemComponent* GetLocalPlayerAbilitySystemComponent() const;

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
};
