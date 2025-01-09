// Thomas Learning Project

#include "UI/AbilitySystem/AuraAttributeBasedProgressBar.h"

#include "AbilitySystemBlueprintLibrary.h"

#include "AbilitySystemComponent.h"

void UAuraAttributeBasedProgressBar::Internal_OwningActorSet()
{
	UAbilitySystemComponent* ASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(OwningActor);

	ASC->GetGameplayAttributeValueChangeDelegate(BaseValueAttribute).AddUObject(this, &UAuraAttributeBasedProgressBar::OnBaseAttributeValueChanged);

	ASC->GetGameplayAttributeValueChangeDelegate(MaxValueAttribute).AddUObject(this, &UAuraAttributeBasedProgressBar::OnMaxAttributeValueChanged);

	bool bFound;

	BaseValue = ASC->GetGameplayAttributeValue(BaseValueAttribute, bFound);

	MaxValue = ASC->GetGameplayAttributeValue(MaxValueAttribute, bFound);

	AttributeValueChanged();

	Super::Internal_OwningActorSet();
}

void UAuraAttributeBasedProgressBar::OnBaseAttributeValueChanged(const FOnAttributeChangeData& Data)
{
	BaseValue = Data.NewValue;

	AttributeValueChanged();
}

void UAuraAttributeBasedProgressBar::OnMaxAttributeValueChanged(const FOnAttributeChangeData& Data)
{
	MaxValue = Data.NewValue;

	AttributeValueChanged();
}
