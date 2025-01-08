// Thomas Learning Project

#pragma once

#include "ContextObject.generated.h"

UCLASS()
class UContextObject : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "ContextObject")
	void SetOwningActor(const AActor* InOwningActor);

protected:
	UPROPERTY(BlueprintReadOnly, Category = "ContextObject")
	TObjectPtr<const AActor> OwningActor;
};
