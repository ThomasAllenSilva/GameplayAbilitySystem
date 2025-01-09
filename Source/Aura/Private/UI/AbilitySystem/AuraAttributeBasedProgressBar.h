// Thomas Learning Project

#pragma once

#include "CoreMinimal.h"

#include "Blueprint/UserWidget.h"

#include "AttributeSet.h"

#include "GameplayEffectTypes.h"

#include "UI/Base/ContextualUserWidget.h"

#include "AuraAttributeBasedProgressBar.generated.h"

UCLASS()
class UAuraAttributeBasedProgressBar final : public UContextualUserWidget
{
	GENERATED_BODY()
	
protected:
	virtual void Internal_OwningActorSet() override;

protected:
	UPROPERTY(BlueprintReadOnly)
	float BaseValue;

	UPROPERTY(BlueprintReadOnly)
	float MaxValue;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	FGameplayAttribute BaseValueAttribute;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	FGameplayAttribute MaxValueAttribute;

	UFUNCTION(BlueprintImplementableEvent)
	void AttributeValueChanged();

private:
	void OnBaseAttributeValueChanged(const FOnAttributeChangeData& Data);

	void OnMaxAttributeValueChanged(const FOnAttributeChangeData& Data);
};
