// Thomas Learning Project

#pragma once

#include "CoreMinimal.h"

#include "Blueprint/UserWidget.h"

#include "AuraPlayerStatusUserWidget.generated.h"

class UAuraAbilitySystemComponent;

struct FGameplayAttribute;

UCLASS()
class UAuraPlayerStatusUserWidget final : public UUserWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnHealthValueChanged(float NewHealthValue);

	UFUNCTION(BlueprintImplementableEvent)
	void OnMaxHealthValueChanged(float NewMaxHealthValue);

	UFUNCTION(BlueprintImplementableEvent)
	void OnManaValueChanged(float NewManaValue);

	UFUNCTION(BlueprintImplementableEvent)
	void OnMaxManaValueChanged(float NewMaxManaValue);

protected:
	virtual void NativeConstruct() override;

private:
	void BindToAttributesChanges();

	void BindAttributeChangeDelegate(UAuraAbilitySystemComponent* PlayerASC, const FGameplayAttribute& Attribute, void (UAuraPlayerStatusUserWidget::* Callback)(float));
};
