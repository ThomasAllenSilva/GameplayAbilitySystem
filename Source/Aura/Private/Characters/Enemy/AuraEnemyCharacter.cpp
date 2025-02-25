// Thomas Learning Project

#include "Characters/Enemy/AuraEnemyCharacter.h"
#include "Components/CommonAbilitySystemComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTree.h"
#include "AI/AuraAIController.h"
#include "AuraNativeGameplayTags.h"

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

	AbilitySystemComponent->RegisterGameplayTagEvent(Common_Event_HitReact, EGameplayTagEventType::AnyCountChange).AddUObject(this, &AAuraEnemyCharacter::HitReactTagChanged);
}

void AAuraEnemyCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	if (HasAuthority() == false)
	{
		return;
	}

	AuraAIController = Cast<AAuraAIController>(NewController);

	AuraAIController->GetBlackboardComponent()->InitializeBlackboard(*BehaviorTree->BlackboardAsset);

	AuraAIController->GetBlackboardComponent()->SetValueAsBool(FName("CanMoveTo"), true);

	AuraAIController->RunBehaviorTree(BehaviorTree);
}

void AAuraEnemyCharacter::HitReactTagChanged(const FGameplayTag Tag, int32 Count)
{
	bool canMove = Count == 0;

	AuraAIController->GetBlackboardComponent()->SetValueAsBool(FName("CanMoveTo"), canMove);
}
