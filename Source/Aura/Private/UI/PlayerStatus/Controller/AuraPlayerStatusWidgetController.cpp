// Thomas Learning Project

#include "UI/PlayerStatus/Controller/AuraPlayerStatusWidgetController.h"

#include "Player/Data/Gas/PlayerGasData.h"

#include "AbilitySystem/AttributeSet/AuraAttributeSet.h"

#include "AbilitySystem/Component/AuraAbilitySystemComponent.h"

void UAuraPlayerStatusWidgetController::SetGasData(UPlayerGasData* GasData)
{
	PlayerGasData = GasData;

	check(GasData);

	FGameplayAttribute HealthAttributeData = PlayerGasData->GetAttributeSet()->GetHealthAttribute();

	PlayerGasData->GetAbilitySystemComponent()->GetGameplayAttributeValueChangeDelegate(HealthAttributeData).AddUObject(this, &UAuraPlayerStatusWidgetController::OnHealthAttribueValueChanged);
}

void UAuraPlayerStatusWidgetController::BroadcastInitialValues()
{
	const UAuraAttributeSet* AttributeSet = PlayerGasData->GetAttributeSet();

	OnHealthValueChanged.Broadcast(AttributeSet->GetHealth());

	OnMaxHealthValueChanged.Broadcast(AttributeSet->GetMaxHealth());

	OnManaValueChanged.Broadcast(AttributeSet->GetMana());

	OnMaxManaValueChanged.Broadcast(AttributeSet->GetMaxMana());
}

void UAuraPlayerStatusWidgetController::BindAttributeDelegatesCallbacks()
{
	const UAuraAttributeSet* AttributeSet = PlayerGasData->GetAttributeSet();

	FGameplayAttribute HealthAttributeData = AttributeSet->GetHealthAttribute();

	PlayerGasData->GetAbilitySystemComponent()->GetGameplayAttributeValueChangeDelegate(HealthAttributeData).AddUObject(this, &UAuraPlayerStatusWidgetController::OnHealthAttribueValueChanged);

	FGameplayAttribute MaxHealthAttributeData = AttributeSet->GetMaxHealthAttribute();

	PlayerGasData->GetAbilitySystemComponent()->GetGameplayAttributeValueChangeDelegate(MaxHealthAttributeData).AddUObject(this, &UAuraPlayerStatusWidgetController::OnMaxHealthAttribueValueChanged);

	FGameplayAttribute ManaAttributeData = AttributeSet->GetManaAttribute();

	PlayerGasData->GetAbilitySystemComponent()->GetGameplayAttributeValueChangeDelegate(ManaAttributeData).AddUObject(this, &UAuraPlayerStatusWidgetController::OnManaAttribueValueChanged);

	FGameplayAttribute MaxManaAttributeData = AttributeSet->GetMaxManaAttribute();

	PlayerGasData->GetAbilitySystemComponent()->GetGameplayAttributeValueChangeDelegate(MaxManaAttributeData).AddUObject(this, &UAuraPlayerStatusWidgetController::OnMaxManaAttribueValueChanged);
}

void UAuraPlayerStatusWidgetController::OnHealthAttribueValueChanged(const FOnAttributeChangeData& HealthData) const
{
	OnHealthValueChanged.Broadcast(HealthData.NewValue);
}

void UAuraPlayerStatusWidgetController::OnMaxHealthAttribueValueChanged(const FOnAttributeChangeData& MaxHealthData) const
{
	OnMaxHealthValueChanged.Broadcast(MaxHealthData.NewValue);
}

void UAuraPlayerStatusWidgetController::OnManaAttribueValueChanged(const FOnAttributeChangeData& ManaData) const
{
	OnManaValueChanged.Broadcast(ManaData.NewValue);
}

void UAuraPlayerStatusWidgetController::OnMaxManaAttribueValueChanged(const FOnAttributeChangeData& MaxManaData) const
{
	OnMaxManaValueChanged.Broadcast(MaxManaData.NewValue);
}