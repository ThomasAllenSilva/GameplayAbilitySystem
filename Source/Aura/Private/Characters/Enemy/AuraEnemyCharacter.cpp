// Thomas Learning Project


#include "Characters/Enemy/AuraEnemyCharacter.h"

#include "AbilitySystem/Component/AuraAbilitySystemComponent.h"

#include "AbilitySystem/AttributeSet/AuraAttributeSet.h"

AAuraEnemyCharacter::AAuraEnemyCharacter()
{
	AbilitySystemComponent = CreateDefaultSubobject<UAuraAbilitySystemComponent>("AbilitySystemComponent");

	AttributeSet = CreateDefaultSubobject<UAuraAttributeSet>("AuraAttributeSetBase");
}
