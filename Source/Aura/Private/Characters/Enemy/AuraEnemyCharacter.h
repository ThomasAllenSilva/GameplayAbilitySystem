// Thomas Learning Project

#pragma once

#include "CoreMinimal.h"

#include "Characters/Base/AuraCharacterBase.h"

#include "AuraEnemyCharacter.generated.h"

class UCommonAbilitySystemComponent;
class AAuraAIController;
class UBehaviorTree;

UCLASS()
class AAuraEnemyCharacter final : public AAuraCharacterBase
{
	GENERATED_BODY()

public:
	AAuraEnemyCharacter();

public:
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

protected:
	virtual void BeginPlay() override;

	virtual void PossessedBy(AController* Controller) override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TObjectPtr<UCommonAbilitySystemComponent> AbilitySystemComponent;

private:
	UPROPERTY(EditDefaultsOnly, Category = "AI", meta = (AllowPrivateAccess))
	TObjectPtr<UBehaviorTree> BehaviorTree;

	UPROPERTY()
	TObjectPtr<AAuraAIController> AuraAIController;
};
