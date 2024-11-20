// Thomas Learning Project

#include "Player/State/AuraPlayerState.h"

#include "AbilitySystem/Component/AuraAbilitySystemComponent.h"

#include "AbilitySystem/AttributeSet/AuraAttributeSet.h"

#include "Player/Data/Gas/PlayerGasData.h"

#include "UI/PlayerStatus/View/AuraPlayerStatusUserWidgetView.h"

#include "UI/PickupsMessages/View/AuraPickupMessageUserWidgetView.h"

#include "UI/PickupsMessages/Controller/AuraPickupWidgetController.h"

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

	CreateWidgets();
}

//What I'm doing here is probably wrong. I should make these widgets creation more flexible.
//Do I know how to do that? Not yet...
void AAuraPlayerState::CreateWidgets()
{
	/*check(PlayerStatusWidgetDefinition.WidgetTemplate);

	UAuraPlayerStatusWidgetController* WidgetController = NewObject<UAuraPlayerStatusWidgetController>(this);

	WidgetController->SetGasData(PlayerGasData);

	UAuraPlayerStatusUserWidgetView* Widget = UAuraUIBlueprintFunctionLibrary::CreateWidgetAtLayer_Internal<UAuraPlayerStatusUserWidgetView>(GetWorld(), PlayerStatusWidgetDefinition.WidgetTemplate, PlayerStatusWidgetDefinition.LayerTag);

	Widget->SetWidgetController(WidgetController);

	WidgetController->BroadcastInitialValues();

	UAuraPickupWidgetController* PickupWidgetController = NewObject<UAuraPickupWidgetController>(this);
	PickupWidgetController->Initialize(AbilitySystemComponent);

	UAuraPickupMessageUserWidgetView* PickupMessageWidget = UAuraUIBlueprintFunctionLibrary::CreateWidgetAtLayer_Internal<UAuraPickupMessageUserWidgetView>(GetWorld(), PickupMessageWidgetDefinition.WidgetTemplate, PickupMessageWidgetDefinition.LayerTag);

	PickupMessageWidget->SetWidgetController(PickupWidgetController);*/

}
