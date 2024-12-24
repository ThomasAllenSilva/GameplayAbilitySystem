// Thomas Learning Project

#pragma once

#include "CoreMinimal.h"

#include "GameFramework/Character.h"

#include "AbilitySystemInterface.h"

#include "AbilitySystem/Interfaces/CombatInterface.h"

#include "AuraCharacterBase.generated.h"

class UAbilitySystemComponent;

class UAuraAttributeSet;

UCLASS(Abstract)
class AAuraCharacterBase : public ACharacter, public IAbilitySystemInterface, public ICombatInterface
{
	GENERATED_BODY()

public:
	AAuraCharacterBase();

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	virtual FVector GetProjectileSpawnLocation() override;

protected:
	UPROPERTY(EditDefaultsOnly, Category = "Combat")
	TObjectPtr<USkeletalMeshComponent> WeaponMesh;

protected:
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UAuraAttributeSet> AttributeSet;
};
