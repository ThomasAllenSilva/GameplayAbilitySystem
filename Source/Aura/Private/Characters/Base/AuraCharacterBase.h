// Thomas Learning Project

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "GameplayTagAssetInterface.h"
#include "AuraCharacterBase.generated.h"

static const FName WeaponSocketName = TEXT("TipSocket");

static const FName WarpName = TEXT("FacingTarget");

class UCommonAbilitySystemComponent;

class UMotionWarpingComponent;

UCLASS(Abstract)
class AAuraCharacterBase : public ACharacter, public IAbilitySystemInterface, public IGameplayTagAssetInterface
{
	GENERATED_BODY()

public:
	AAuraCharacterBase();

	//~AbilitySystem Interface
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const;
	//~ End of AbilitySystem Interface

	//~GameplayTagAsset Interface
	virtual void GetOwnedGameplayTags(FGameplayTagContainer& TagContainer) const override;

	virtual bool HasMatchingGameplayTag(FGameplayTag TagToCheck) const override;

	virtual bool HasAnyMatchingGameplayTags(const FGameplayTagContainer& TagContainer) const override;

	virtual bool HasAllMatchingGameplayTags(const FGameplayTagContainer& TagContainer) const override;
	//~End of GameplayTagAsset Interface

	UFUNCTION(BlueprintCallable, BlueprintPure)
	FVector GetWeaponSocketLocation() const;

	UFUNCTION(BlueprintCallable)
	void UpdateWarpTargetFromLocation(const FVector& Location);

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Combat")
	TObjectPtr<USkeletalMeshComponent> WeaponMesh;

private:
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UMotionWarpingComponent> MotionWarpingComponent;
};
