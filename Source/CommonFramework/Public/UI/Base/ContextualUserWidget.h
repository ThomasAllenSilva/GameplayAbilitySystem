// Thomas Learning Project

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ContextualUserWidget.generated.h"

UCLASS()
class COMMONFRAMEWORK_API UContextualUserWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "ContextObject")
	void SetOwningActor(AActor* InOwningActor);

protected:
	virtual void Internal_OwningActorSet();

	UFUNCTION(BlueprintImplementableEvent, Category = "ContextObject")
	void OwningActorSet(AActor* InOwningActor);

protected:
	UPROPERTY(BlueprintReadOnly, Category = "ContextObject")
	TObjectPtr<AActor> OwningActor;
};
