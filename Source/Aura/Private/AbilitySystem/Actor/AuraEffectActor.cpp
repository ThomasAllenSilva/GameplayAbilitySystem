// Thomas Learning Project

#include "AbilitySystem/Actor/AuraEffectActor.h"

#include "AbilitySystemGlobals.h"

#include "AbilitySystemComponent.h"

AAuraEffectActor::AAuraEffectActor()
{
	PrimaryActorTick.bCanEverTick = false;

	PrimaryActorTick.bStartWithTickEnabled = false;

	PrimaryActorTick.bAllowTickOnDedicatedServer = false;
}

void AAuraEffectActor::ApplyEffectToActor(const AActor* TargetActor, TSubclassOf<UGameplayEffect> Effect, bool bDestroyOnEffectApplication)
{
	ApplyEffectToTargetActor(TargetActor, Effect, bDestroyOnEffectApplication);
}

void AAuraEffectActor::ApplyEffectsToActor(const AActor* TargetActor, TArray<TSubclassOf<UGameplayEffect>> EffectsToApply, bool bDestroyOnEffectApplication)
{
	for (TSubclassOf<UGameplayEffect>& effect : EffectsToApply)
	{
		ApplyEffectToTargetActor(TargetActor, effect, bDestroyOnEffectApplication);
	}
}

void AAuraEffectActor::RemoveEffectFromActor(const AActor* TargetActor, TSubclassOf<UGameplayEffect> EffectToRemove, bool bRemoveAsSingleStack, bool bDestroyOnEffectRemoval)
{
	RemoveEffectFromTargetActor(TargetActor, EffectToRemove, bRemoveAsSingleStack, bDestroyOnEffectRemoval);
}

void AAuraEffectActor::RemoveEffectsFromActor(const AActor* TargetActor, TArray<TSubclassOf<UGameplayEffect>> EffectsToRemove, bool bRemoveAsSingleStack, bool bDestroyOnEffectRemoval)
{
	for (TSubclassOf<UGameplayEffect>& effect : EffectsToRemove)
	{
		RemoveEffectFromTargetActor(TargetActor, effect, bRemoveAsSingleStack, bDestroyOnEffectRemoval);
	}
}

void AAuraEffectActor::ApplyEffectToTargetActor(const AActor* TargetActor, TSubclassOf<UGameplayEffect> Effect, bool bDestroyOnEffectApplication)
{
	check(Effect);

	UAbilitySystemComponent* TargetASC = UAbilitySystemGlobals::GetAbilitySystemComponentFromActor(TargetActor);

	if (TargetASC == nullptr)
	{
		return;
	}

	FGameplayEffectContextHandle EffectContextHandle = TargetASC->MakeEffectContext();

	EffectContextHandle.AddSourceObject(this);

	FGameplayEffectSpecHandle EffectSpecHandle = TargetASC->MakeOutgoingSpec(Effect, 1.0f, EffectContextHandle);

	TargetASC->ApplyGameplayEffectSpecToSelf(*EffectSpecHandle.Data.Get());

	if (bDestroyOnEffectApplication)
	{
		Destroy();
	}
}

void AAuraEffectActor::RemoveEffectFromTargetActor(const AActor* TargetActor, TSubclassOf<UGameplayEffect> Effect, bool bRemoveAsSingleStack, bool bDestroyOnEffectRemoval)
{
	check(Effect);

	UAbilitySystemComponent* TargetASC = UAbilitySystemGlobals::GetAbilitySystemComponentFromActor(TargetActor);

	if (TargetASC == nullptr)
	{
		return;
	}

	TargetASC->RemoveActiveGameplayEffectBySourceEffect(Effect, nullptr, 1);

	if (bDestroyOnEffectRemoval)
	{
		Destroy();
	}
}
