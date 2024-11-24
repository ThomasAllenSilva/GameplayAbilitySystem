// Thomas Learning Project

#include "AuraPlayerStatusUserWidget.h"

#include "AuraBlueprintFunctionLibrary.h"

#include "AbilitySystem/AttributeSet/AuraAttributeSet.h"

#include "AbilitySystem/Component/AuraAbilitySystemComponent.h"

void UAuraPlayerStatusUserWidget::NativeConstruct()
{
	InitPlayerStatusValues();

	BindToAttributesChanges();

	Super::NativeConstruct();
}

void UAuraPlayerStatusUserWidget::InitPlayerStatusValues()
{
	const UAuraAttributeSet* AttributeSet = UAuraBlueprintFunctionLibrary::GetLocalPlayerAttributeSet(this);

	Health = AttributeSet->GetHealth();

	MaxHealth = AttributeSet->GetMaxHealth();

	Mana = AttributeSet->GetMana();

	MaxMana = AttributeSet->GetMaxMana();
}

void UAuraPlayerStatusUserWidget::BindToAttributesChanges()
{
	const UAuraAttributeSet* AttributeSet = UAuraBlueprintFunctionLibrary::GetLocalPlayerAttributeSet(this);

	UAuraAbilitySystemComponent* PlayerASC = UAuraBlueprintFunctionLibrary::GetLocalPlayerAbilitySystemComponent(this);

	BindAttributeChangeDelegate(PlayerASC, AttributeSet->GetHealthAttribute(), &UAuraPlayerStatusUserWidget::OnHealthValueChanged, Health);

	BindAttributeChangeDelegate(PlayerASC, AttributeSet->GetMaxHealthAttribute(), &UAuraPlayerStatusUserWidget::OnMaxHealthValueChanged, MaxHealth);

	BindAttributeChangeDelegate(PlayerASC, AttributeSet->GetManaAttribute(), &UAuraPlayerStatusUserWidget::OnManaValueChanged, Mana);

	BindAttributeChangeDelegate(PlayerASC, AttributeSet->GetMaxManaAttribute(), &UAuraPlayerStatusUserWidget::OnMaxManaValueChanged, MaxMana);
}

void UAuraPlayerStatusUserWidget::BindAttributeChangeDelegate(UAuraAbilitySystemComponent* PlayerASC, const FGameplayAttribute& Attribute, void (UAuraPlayerStatusUserWidget::* Callback)(), float& WidgetAttributeValue)
{
	PlayerASC->GetGameplayAttributeValueChangeDelegate(Attribute).AddWeakLambda(this,
		[this, Callback, &WidgetAttributeValue](const FOnAttributeChangeData& Data)
		{
			WidgetAttributeValue = Data.NewValue;
			(this->*Callback)();
		});
}
