// Thomas Learning Project

#pragma once

#include "CoreMinimal.h"

#include "GameFramework/Actor.h"

#include "AuraEffectActor.generated.h"

UCLASS()
class AAuraEffectActor final : public AActor
{
	GENERATED_BODY()

public:
	AAuraEffectActor();

protected:
	UFUNCTION(BlueprintCallable)
	void ApplyEffectToActor(const AActor* TargetActor, TSubclassOf<UGameplayEffect> EffectToApply, bool bDestroyOnEffectApplication = false);

	UFUNCTION(BlueprintCallable)
	void ApplyEffectsToActor(const AActor* TargetActor, TArray<TSubclassOf<UGameplayEffect>> EffectsToApply, bool bDestroyOnEffectApplication = false);

	UFUNCTION(BlueprintCallable)
	void RemoveEffectFromActor(const AActor* TargetActor, TSubclassOf<UGameplayEffect> EffectToRemove, bool bRemoveAsSingleStack = true, bool bDestroyOnEffectRemoval = false);

	UFUNCTION(BlueprintCallable)
	void RemoveEffectsFromActor(const AActor* TargetActor, TArray<TSubclassOf<UGameplayEffect>> EffectsToRemove, bool bRemoveAsSingleStack = true, bool bDestroyOnEffectRemoval = false);

private:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TArray<TSubclassOf<UGameplayEffect>> InstantEffects;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TArray<TSubclassOf<UGameplayEffect>> DurationEffects;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TArray<TSubclassOf<UGameplayEffect>> InfiniteEffects;

private:
	void ApplyEffectToTargetActor(const AActor* TargetActor, TSubclassOf<UGameplayEffect> EffectToApply, bool bDestroyOnEffectApplication);

	void RemoveEffectFromTargetActor(const AActor* TargetActor, TSubclassOf<UGameplayEffect> EffectToRemove, bool bRemoveAsSingleStack, bool bDestroyOnEffectRemoval);
};
