// Thomas Learning Project

#include "Player/State/AuraPlayerState.h"

#include "AbilitySystem/Component/AuraAbilitySystemComponent.h"

#include "AbilitySystem/AttributeSet/AuraAttributeSet.h"

#include "AbilitySystem/AttributeSet/AuraPrimaryAttributeSet.h"

#include "AbilitySystem/AttributeSet/AuraSecondaryAttributeSet.h"

#include "AbilitySystem/AttributeSet/AuraVitalAttributeSet.h"

#include "Player/Data/Gas/PlayerGasData.h"

AAuraPlayerState::AAuraPlayerState()
{
	AbilitySystemComponent = CreateDefaultSubobject<UAuraAbilitySystemComponent>("AbilitySystemComponent");

	AttributeSet = CreateDefaultSubobject<UAuraAttributeSet>("AuraAttributeSetBase");

	PrimaryAttributeSet = CreateDefaultSubobject<UAuraPrimaryAttributeSet>("AuraPrimaryAttributeSet");

	SecondaryAttributeSet = CreateDefaultSubobject<UAuraSecondaryAttributeSet>("AuraSecondaryAttributeSet");

	//VitalAttributeSet = CreateDefaultSubobject<UAuraVitalAttributeSet>("AuraVitalAttributeSet");
}

UAbilitySystemComponent* AAuraPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

UAuraAttributeSet* AAuraPlayerState::GetAttributeSet() const
{
	return AttributeSet;
}

void AAuraPlayerState::BeginPlay()
{
	Super::BeginPlay();

	checkf(GetPawn(), TEXT("NULL Pawn When Initing Ability Actor Info"));

	AbilitySystemComponent->InitAbilityActorInfo(this, GetPawn());

	PlayerGasData = NewObject<UPlayerGasData>(this);

	PlayerGasData->InitializeData(AbilitySystemComponent, AttributeSet);

	OnExecutedBeginPlay();
}