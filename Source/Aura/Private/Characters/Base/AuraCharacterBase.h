// Thomas Learning Project

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "AbilitySystem/Interfaces/CombatInterface.h"
#include "GameplayTagAssetInterface.h"
#include "AuraCharacterBase.generated.h"

class UCommonAbilitySystemComponent;

class UMotionWarpingComponent;

UCLASS(Abstract)
class AAuraCharacterBase : public ACharacter, public IAbilitySystemInterface, public ICombatInterface, public IGameplayTagAssetInterface
{
	GENERATED_BODY()

public:
	AAuraCharacterBase();

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const;

	//~ Begin Combat Interface
	virtual FVector GetWeaponSocketLocation() override;

	virtual void UpdateWarpTargetFromLocation(const FVector& Location) override;

	virtual void SetTargetActor(AActor* InTargetActor) override;

	virtual AActor* GetTargetActor() const override;

	virtual AActor* GetTargetActorChecked() const override;

	virtual void ClearTargetActor() override;
	//~ End Combat Interface

	//~ Begin GameplayTagAsset Interface
	virtual void GetOwnedGameplayTags(FGameplayTagContainer& TagContainer) const override;

	virtual bool HasMatchingGameplayTag(FGameplayTag TagToCheck) const override;

	virtual bool HasAnyMatchingGameplayTags(const FGameplayTagContainer& TagContainer) const override;

	virtual bool HasAllMatchingGameplayTags(const FGameplayTagContainer& TagContainer) const override;
	//~ End GameplayTagAsset Interface

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Combat")
	TObjectPtr<USkeletalMeshComponent> WeaponMesh;

private:
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UMotionWarpingComponent> MotionWarpingComponent;

	/* The current actor that is being aimed at or attacked. */
	TWeakObjectPtr<AActor> TargetActor;
};
