// Thomas Learning Project

#include "Player/State/AuraPlayerState.h"

#include "AbilitySystem/Component/AuraAbilitySystemComponent.h"

#include "AbilitySystem/AttributeSet/AuraAttributeSet.h"

#include "Player/Data/Gas/PlayerGasData.h"

#include "UI/PlayerStatus/View/AuraPlayerStatusUserWidgetView.h"

#include "UI/PlayerStatus/Controller/AuraPlayerStatusWidgetController.h"

AAuraPlayerState::AAuraPlayerState()
{
	AbilitySystemComponent = CreateDefaultSubobject<UAuraAbilitySystemComponent>("AbilitySystemComponent");

	AttributeSet = CreateDefaultSubobject<UAuraAttributeSet>("AuraAttributeSetBase");
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

	check(GetPawn());

	AbilitySystemComponent->InitAbilityActorInfo(this, GetPawn());

	PlayerGasData = NewObject<UPlayerGasData>(this);

	PlayerGasData->InitializeData(AbilitySystemComponent, AttributeSet);

	CreateAttributesStatusWidget();
}

void AAuraPlayerState::CreateAttributesStatusWidget()
{
	check(PlayerStatusWidgetTemplate);

	UAuraPlayerStatusUserWidgetView* Widget = CreateWidget<UAuraPlayerStatusUserWidgetView>(GetWorld(), PlayerStatusWidgetTemplate);

	UAuraPlayerStatusWidgetController* WidgetController = NewObject<UAuraPlayerStatusWidgetController>(this);

	WidgetController->SetGasData(PlayerGasData);

	Widget->AddToViewport();

	Widget->SetWidgetController(WidgetController);

	WidgetController->BroadcastInitialValues();
}
