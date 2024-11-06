// Thomas Learning Project

#include "AbilitySystem/AttributeSet/AuraAttributeSet.h"

UAuraAttributeSet::UAuraAttributeSet()
{
	InitHealth(75.0f);

	InitMaxHealth(100.0f);

	InitMana(25.0f);

	InitMaxMana(50.0f);
}

void UAuraAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	TryClampAttributeValueChange(Attribute, NewValue);
}

void UAuraAttributeSet::PreAttributeBaseChange(const FGameplayAttribute& Attribute, float& NewValue) const
{
	TryClampAttributeValueChange(Attribute, NewValue);
}

void UAuraAttributeSet::TryClampAttributeValueChange(const FGameplayAttribute& Attribute, float& NewValue) const
{
	//TODO: Change These Hard-Coded Clamp Values To Something More Flexible
	if (Attribute == GetHealthAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.0f, 100.0f);
	}

	if (Attribute == GetManaAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.0f, 100.0f);
	}
}
