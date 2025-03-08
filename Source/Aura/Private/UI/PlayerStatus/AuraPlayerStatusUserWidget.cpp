// Thomas Learning Project

#include "AuraPlayerStatusUserWidget.h"
#include "AbilitySystem/AttributeSets/AuraVitalAttributeSet.h"
#include "CommonAbilityFunctionLibrary.h"
#include "Components/CommonAbilitySystemComponent.h"

void UAuraPlayerStatusUserWidget::NativeConstruct()
{
	Super::NativeConstruct();

	UCommonAbilitySystemComponent* ASC = UCommonAbilityFunctionLibrary::GetLocalPlayerAbilitySystemComponent(this);

	InitPlayerStatusValues();

	BindToAttributesChanges();
}

void UAuraPlayerStatusUserWidget::InitPlayerStatusValues()
{
	const UCommonAbilitySystemComponent* ASC = UCommonAbilityFunctionLibrary::GetLocalPlayerAbilitySystemComponent(this);

	bool bFound;

	Health = ASC->GetGameplayAttributeValue(UAuraVitalAttributeSet::GetHealthAttribute(), bFound);

	MaxHealth = ASC->GetGameplayAttributeValue(UAuraVitalAttributeSet::GetMaxHealthAttribute(), bFound);

	Mana = ASC->GetGameplayAttributeValue(UAuraVitalAttributeSet::GetManaAttribute(), bFound);

	MaxMana = ASC->GetGameplayAttributeValue(UAuraVitalAttributeSet::GetMaxManaAttribute(), bFound);

	OnHealthValueChanged();

	OnManaValueChanged();

	check(bFound);
}

void UAuraPlayerStatusUserWidget::BindToAttributesChanges()
{
	UCommonAbilitySystemComponent* PlayerASC = UCommonAbilityFunctionLibrary::GetLocalPlayerAbilitySystemComponent(this);

	BindAttributeChangeDelegate(PlayerASC, UAuraVitalAttributeSet::GetMaxHealthAttribute(), &UAuraPlayerStatusUserWidget::OnMaxHealthValueChanged, MaxHealth);

	BindAttributeChangeDelegate(PlayerASC, UAuraVitalAttributeSet::GetMaxManaAttribute(), &UAuraPlayerStatusUserWidget::OnMaxManaValueChanged, MaxMana);

	BindAttributeChangeDelegate(PlayerASC, UAuraVitalAttributeSet::GetHealthAttribute(), &UAuraPlayerStatusUserWidget::OnHealthValueChanged, Health);

	BindAttributeChangeDelegate(PlayerASC, UAuraVitalAttributeSet::GetManaAttribute(), &UAuraPlayerStatusUserWidget::OnManaValueChanged, Mana);

}

void UAuraPlayerStatusUserWidget::BindAttributeChangeDelegate(UCommonAbilitySystemComponent* PlayerASC, const FGameplayAttribute& Attribute, void (UAuraPlayerStatusUserWidget::* Callback)(), float& WidgetAttributeValue)
{
	PlayerASC->GetGameplayAttributeValueChangeDelegate(Attribute).AddWeakLambda(this,
		[this, Callback, &WidgetAttributeValue](const FOnAttributeChangeData& Data)
		{
			WidgetAttributeValue = Data.NewValue;
			(this->*Callback)();
		});
}
