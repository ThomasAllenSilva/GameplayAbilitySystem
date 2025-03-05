// Thomas Learning Project

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "CommonGameplayAbility.generated.h"

UENUM()
enum class EAbilityActivationPolicy
{
	OnGiven,

	OnTriggered
};

/**
 *
 */
UCLASS()
class COMMONABILITYSYSTEM_API UCommonGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	virtual void OnGiveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec) override;

	virtual void EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled) override;

	virtual void OnRemoveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec) override;

	/** Called when the ability is given to an AbilitySystemComponent */
	UFUNCTION(BlueprintImplementableEvent, Category = "Ability")
	void OnAbilityGiven(const FGameplayAbilityActorInfo& ActorInfo);

	/** Called when the ability is removed from an AbilitySystemComponent */
	UFUNCTION(BlueprintImplementableEvent, Category = "Ability")
	void OnAbilityRemoved(const FGameplayAbilityActorInfo& ActorInfo, const FGameplayAbilitySpec& Spec);

private:
	/*Specifies if the ability is activated when its given to an ASC or triggered later. Used on OnGiveAbility callback*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Common Settings", meta = (AllowPrivateAccess))
	EAbilityActivationPolicy ActivationPolicy = EAbilityActivationPolicy::OnTriggered;

	/*Specifies if the ability should be removed from the ASC when the ability ends*/
	UPROPERTY(EditDefaultsOnly, Category = "Common Settings", meta = (AllowPrivateAccess))
	bool bShouldRemoveOnEndAbility = false;
};
