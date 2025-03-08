// Thomas Learning Project

#pragma once

#include "CoreMinimal.h"
#include "Characters/Base/AuraCharacterBase.h"
#include "AuraEnemyCharacter.generated.h"

class UCommonAbilitySystemComponent;
class AAuraAIController;
class UBehaviorTree;
struct FGameplayTag;

UCLASS()
class AAuraEnemyCharacter final : public AAuraCharacterBase
{
	GENERATED_BODY()

public:
	AAuraEnemyCharacter();

public:
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	UFUNCTION(BlueprintCallable)
	void SetTargetActor(AActor* InTargetActor);

	UFUNCTION(BlueprintCallable, BlueprintPure)
	AActor* GetTargetActor() const;

	UFUNCTION(BlueprintCallable, BlueprintPure)
	AActor* GetTargetActorChecked() const;

	UFUNCTION(BlueprintCallable, BlueprintPure)
	FVector GetTargetActorLocation() const;

	UFUNCTION(BlueprintCallable)
	void ClearTargetActor();

protected:
	virtual void BeginPlay() override;

	virtual void PossessedBy(AController* Controller) override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TObjectPtr<UCommonAbilitySystemComponent> AbilitySystemComponent;

private:
	void HitReactTagChanged(const FGameplayTag Tag, int32 Count);

private:
	UPROPERTY(EditDefaultsOnly, Category = "AI", meta = (AllowPrivateAccess))
	TObjectPtr<UBehaviorTree> BehaviorTree;

	UPROPERTY()
	TObjectPtr<AAuraAIController> AuraAIController;

	/* The current actor that is being aimed at or attacked. */
	TWeakObjectPtr<AActor> TargetActor;
};
