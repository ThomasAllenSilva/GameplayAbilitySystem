// Thomas Learning Project


#include "Player/Data/Gas/PlayerGasData.h"

void UPlayerGasData::InitializeData(UAuraAbilitySystemComponent* InASC, UAuraAttributeSet* InAttributeSet)
{
	AbilitySystemComponent = InASC;

	AttributeSet = InAttributeSet;
}
