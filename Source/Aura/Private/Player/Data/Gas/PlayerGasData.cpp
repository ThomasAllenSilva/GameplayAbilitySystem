// Thomas Learning Project


#include "Player/Data/Gas/PlayerGasData.h"

#include "AbilitySystem/AttributeSet/AuraAttributeSet.h"

#include "AbilitySystem/Component/AuraAbilitySystemComponent.h"

#include "GameplayEffectTypes.h"

void UPlayerGasData::InitializeData(UAuraAbilitySystemComponent* InASC, UAuraAttributeSet* InAttributeSet)
{
	AbilitySystemComponent = InASC;

	AttributeSet = InAttributeSet;

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AttributeSet->GetHealthAttribute()).AddUObject(this, &UPlayerGasData::HealthValueChanged);
}

void UPlayerGasData::BeginDestroy()
{
	Super::BeginDestroy();

	if (AbilitySystemComponent && AttributeSet)
	{
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AttributeSet->GetHealthAttribute()).RemoveAll(this);
	}
}

void UPlayerGasData::HealthValueChanged(const FOnAttributeChangeData& Data)
{
	
}
