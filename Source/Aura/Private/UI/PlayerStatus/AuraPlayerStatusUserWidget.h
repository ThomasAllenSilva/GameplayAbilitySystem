// Thomas Learning Project

#pragma once

#include "CoreMinimal.h"

#include "Blueprint/UserWidget.h"

#include "AuraPlayerStatusUserWidget.generated.h"

class UCommonAbilitySystemComponent;

struct FGameplayAttribute;

UCLASS()
class UAuraPlayerStatusUserWidget final : public UUserWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnHealthValueChanged();

	UFUNCTION(BlueprintImplementableEvent)
	void OnMaxHealthValueChanged();

	UFUNCTION(BlueprintImplementableEvent)
	void OnManaValueChanged();

	UFUNCTION(BlueprintImplementableEvent)
	void OnMaxManaValueChanged();

protected:
	virtual void NativeConstruct() override;

private:
	UPROPERTY(BlueprintReadOnly, Category = "Player Status", meta = (AllowPrivateAccess = "true"))
	float Health;

	UPROPERTY(BlueprintReadOnly, Category = "Player Status", meta = (AllowPrivateAccess = "true"))
	float MaxHealth;

	UPROPERTY(BlueprintReadOnly, Category = "Player Status", meta = (AllowPrivateAccess = "true"))
	float Mana;

	UPROPERTY(BlueprintReadOnly, Category = "Player Status", meta = (AllowPrivateAccess = "true"))
	float MaxMana;

private:
	void InitPlayerStatusValues();

	void BindToAttributesChanges();

	void BindAttributeChangeDelegate(UCommonAbilitySystemComponent* PlayerASC, const FGameplayAttribute& Attribute, void (UAuraPlayerStatusUserWidget::* Callback)(), float& WidgetAttributeValue);
};
