// Thomas Learning Project

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DebugActorComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DEBUGUTILS_API UDebugActorComponent final : public UActorComponent
{
	GENERATED_BODY()

public:	
	UDebugActorComponent();

protected:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent);

private:
	void DisplayDebuggableObjects();


private:
	UPROPERTY(EditAnywhere)
	bool bActive = false;

	UPROPERTY(EditAnywhere)
	bool bDisplayComponents = true;

	UPROPERTY(EditAnywhere)
	bool bDisplayGameplayAbilities = true;
};
