// Thomas Learning Project

#pragma once

#include "CoreMinimal.h"
#include "Characters/Base/AuraCharacterBase.h"
#include "ScalableFloat.h"
#include "AuraEnemyCharacter.generated.h"

class UCommonAbilitySystemComponent;
class AAuraAIController;
class UBehaviorTree;
struct FGameplayTag;

UCLASS(Abstract)
class AAuraEnemyCharacter : public AAuraCharacterBase
{
	GENERATED_BODY()

public:
	AAuraEnemyCharacter();

public:
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	virtual void Die() override;

protected:
	virtual void BeginPlay() override;

	virtual void PossessedBy(AController* Controller) override;

	UFUNCTION(BlueprintImplementableEvent)
	void DissolveCharacterMaterial(UMaterialInstanceDynamic* DynamicMaterialInstance);

	UFUNCTION(BlueprintImplementableEvent)
	void DissolveWeaponMaterial(UMaterialInstanceDynamic* DynamicMaterialInstance);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TObjectPtr<UCommonAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY(EditDefaultsOnly, Category = "Death")
	TObjectPtr<UMaterialInstance> CharacterDissolveMaterial;

	UPROPERTY(EditDefaultsOnly, Category = "Death")
	TObjectPtr<UMaterialInstance> WeaponDissolveMaterial;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Death")
	float LifeSpanAfterDeath;

private:
	void HitReactTagChanged(const FGameplayTag Tag, int32 Count);

private:
	UPROPERTY(EditDefaultsOnly, Category = "AI", meta = (AllowPrivateAccess))
	TObjectPtr<UBehaviorTree> BehaviorTree;

	UPROPERTY()
	TObjectPtr<AAuraAIController> AuraAIController;
};
