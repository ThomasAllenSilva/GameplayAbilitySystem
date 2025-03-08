// Thomas Learning Project

#include "UI/AbilitySystem/AuraAttributeBasedProgressBar.h"
#include "Components/CommonAbilitySystemComponent.h"
#include "CommonAbilityFunctionLibrary.h"

void UAuraAttributeBasedProgressBar::Internal_OwningActorSet()
{
	Super::Internal_OwningActorSet();

	UCommonAbilitySystemComponent* ASC = UCommonAbilityFunctionLibrary::GetCommonAbilitySystemComponentFromActor(OwningActor);

	OnAbilitySystemComponentAvailable(ASC);
}

void UAuraAttributeBasedProgressBar::OnAbilitySystemComponentAvailable(UCommonAbilitySystemComponent* ASC)
{
	ASC->GetGameplayAttributeValueChangeDelegate(MaxValueAttribute).AddUObject(this, &UAuraAttributeBasedProgressBar::OnMaxAttributeValueChanged);

	ASC->GetGameplayAttributeValueChangeDelegate(BaseValueAttribute).AddUObject(this, &UAuraAttributeBasedProgressBar::OnBaseAttributeValueChanged);

	bool bFound;

	MaxValue = ASC->GetGameplayAttributeValue(MaxValueAttribute, bFound);

	BaseValue = ASC->GetGameplayAttributeValue(BaseValueAttribute, bFound);

	check(bFound);

	SetupInitialValues();
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
