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

	virtual FVector GetProjectileSpawnLocation() override;

	virtual void UpdateWarpTargetFromLocation(const FVector& Location) override;


	//interface
	virtual void GetOwnedGameplayTags(FGameplayTagContainer& TagContainer) const override;
	virtual bool HasMatchingGameplayTag(FGameplayTag TagToCheck) const override;
	virtual bool HasAnyMatchingGameplayTags(const FGameplayTagContainer& TagContainer) const override;
	virtual bool HasAllMatchingGameplayTags(const FGameplayTagContainer& TagContainer) const override;
	//end interface
protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Combat")
	TObjectPtr<USkeletalMeshComponent> WeaponMesh;

private:
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UMotionWarpingComponent> MotionWarpingComponent;
};
