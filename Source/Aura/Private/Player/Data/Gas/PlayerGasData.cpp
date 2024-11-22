// Thomas Learning Project


#include "Player/Data/Gas/PlayerGasData.h"

#include "AbilitySystem/AttributeSet/AuraAttributeSet.h"

#include "AbilitySystem/Component/AuraAbilitySystemComponent.h"

void UPlayerGasData::InitializeData(UAuraAbilitySystemComponent* InASC, UAuraAttributeSet* InAttributeSet)
{
	AbilitySystemComponent = InASC;

	AttributeSet = InAttributeSet;
}
