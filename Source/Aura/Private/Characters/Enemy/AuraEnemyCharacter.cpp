// Thomas Learning Project


#include "Characters/Enemy/AuraEnemyCharacter.h"
#include "Components/CommonAbilitySystemComponent.h"

AAuraEnemyCharacter::AAuraEnemyCharacter()
{
	AbilitySystemComponent = CreateDefaultSubobject<UCommonAbilitySystemComponent>("AbilitySystemComponent");
}

UAbilitySystemComponent* AAuraEnemyCharacter::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void AAuraEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();

	AbilitySystemComponent->InitAbilityActorInfo(this, this);
}
