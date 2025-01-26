// Thomas Learning Project


#include "Characters/Enemy/AuraEnemyCharacter.h"

#include "AbilitySystem/Component/AuraAbilitySystemComponent.h"

AAuraEnemyCharacter::AAuraEnemyCharacter()
{
	AbilitySystemComponent = CreateDefaultSubobject<UAuraAbilitySystemComponent>("AbilitySystemComponent");
}

void AAuraEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();

	AbilitySystemComponent->InitAbilityActorInfo(this, this);
}
