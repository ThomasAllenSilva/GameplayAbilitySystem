// Thomas Learning Project

#pragma once

#include "CoreMinimal.h"
#include "Ability/CommonGameplayAbility.h"
#include "DebuggableObjectInterface.h"
#include "AuraGameplayAbility.generated.h"

class AAuraCharacterBase;

/**
 * The base gameplay ability class used by this project.
 */
UCLASS(Abstract)
class UAuraGameplayAbility : public UCommonGameplayAbility, public IDebuggableObjectInterface
{
	GENERATED_BODY()
	
protected:
	virtual void OnGiveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec) override;

	virtual void OnRemoveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec) override;

	/* Returns the Aura Character that owns this ability */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Aura|Ability")
	AAuraCharacterBase* GetAuraCharacterFromActorInfo() const;

protected:
	/** The Aura Character that owns this ability */
	UPROPERTY(BlueprintReadOnly, Category = "Aura Ability")
	TWeakObjectPtr<AAuraCharacterBase>	OwnerAuraCharacter;
};
