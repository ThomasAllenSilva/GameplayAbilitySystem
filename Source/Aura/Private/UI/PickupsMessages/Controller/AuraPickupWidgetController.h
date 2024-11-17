// Thomas Learning Project

#pragma once

#include "CoreMinimal.h"

#include "UObject/NoExportTypes.h"

#include "AuraPickupWidgetController.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnRequestedPickupMessageSignature, const FGameplayTag&, MessageTag);

class UAuraAbilitySystemComponent;

UCLASS()
class UAuraPickupWidgetController final : public UObject
{
	GENERATED_BODY()

public:
	void Initialize(UAuraAbilitySystemComponent* InPlayerASC);

	FOnRequestedPickupMessageSignature OnRequestedPickupMessage;

private:
	UPROPERTY()
	TObjectPtr<UAuraAbilitySystemComponent> PlayerASC;
};
