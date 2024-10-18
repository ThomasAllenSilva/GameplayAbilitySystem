// Thomas Learning Project

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AuraPlayerStatusWidgetController.generated.h"

class UPlayerGasData;

UCLASS()
class UAuraPlayerStatusWidgetController : public UObject
{
	GENERATED_BODY()
	
public:
	void SetGasData(UPlayerGasData* GasData);

private:
	UPROPERTY()
	TObjectPtr<UPlayerGasData> PlayerGasData;
};
