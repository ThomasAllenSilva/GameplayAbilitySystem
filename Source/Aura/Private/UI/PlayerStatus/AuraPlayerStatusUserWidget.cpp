// Thomas Learning Project

#include "AuraPlayerStatusUserWidget.h"

#include "AuraBlueprintFunctionLibrary.h"

#include "AbilitySystem/AttributeSet/AuraAttributeSet.h"

#include "AbilitySystem/Component/AuraAbilitySystemComponent.h"

void UAuraPlayerStatusUserWidget::NativeConstruct()
{
	Super::NativeConstruct();

	BindToAttributesChanges();
}

void UAuraPlayerStatusUserWidget::BindToAttributesChanges()
{
	const UAuraAttributeSet* AttributeSet = UAuraBlueprintFunctionLibrary::GetLocalPlayerAttributeSet(this);

	UAuraAbilitySystemComponent* PlayerASC = UAuraBlueprintFunctionLibrary::GetLocalPlayerAbilitySystemComponent(this);

	BindAttributeChangeDelegate(PlayerASC, AttributeSet->GetHealthAttribute(), &UAuraPlayerStatusUserWidget::OnHealthValueChanged);

	BindAttributeChangeDelegate(PlayerASC, AttributeSet->GetMaxHealthAttribute(), &UAuraPlayerStatusUserWidget::OnMaxHealthValueChanged);

	BindAttributeChangeDelegate(PlayerASC, AttributeSet->GetManaAttribute(), &UAuraPlayerStatusUserWidget::OnManaValueChanged);

	BindAttributeChangeDelegate(PlayerASC, AttributeSet->GetMaxManaAttribute(), &UAuraPlayerStatusUserWidget::OnMaxManaValueChanged);
}

void UAuraPlayerStatusUserWidget::BindAttributeChangeDelegate(UAuraAbilitySystemComponent* PlayerASC, const FGameplayAttribute& Attribute, void (UAuraPlayerStatusUserWidget::* Callback)(float))
{
	PlayerASC->GetGameplayAttributeValueChangeDelegate(Attribute).AddWeakLambda(this,
		[this, Callback](const FOnAttributeChangeData& Data)
		{
			(this->*Callback)(Data.NewValue);
		});
}