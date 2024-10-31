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

void AAuraEffectActor::ApplyEffectToActor(const AActor* Target, TSubclassOf<UGameplayEffect> EffectToApply)
{
	check(EffectToApply);

	UAbilitySystemComponent* TargetASC = UAbilitySystemGlobals::GetAbilitySystemComponentFromActor(Target);

	if (TargetASC == nullptr)
	{
		return;
	}

	FGameplayEffectContextHandle EffectContextHandle = TargetASC->MakeEffectContext();

	EffectContextHandle.AddInstigator(this, this);

	FGameplayEffectSpecHandle EffectSpecHandle = TargetASC->MakeOutgoingSpec(EffectToApply, 1.0f, EffectContextHandle);

	TargetASC->ApplyGameplayEffectSpecToSelf(*EffectSpecHandle.Data.Get());
}
