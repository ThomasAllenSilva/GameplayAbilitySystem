// Thomas Learning Project


#include "AbilitySystem/AsyncActions/AsyncAction_CooldownChanged.h"
#include "AbilitySystemComponent.h"
#include "CommonAbilityFunctionLibrary.h"

UAsyncAction_CooldownChanged* UAsyncAction_CooldownChanged::ListenForCooldownChange(UAbilitySystemComponent* AbilitySystemComponent, FGameplayTag CooldownTag)
{
	UAsyncAction_CooldownChanged* Action = NewObject<UAsyncAction_CooldownChanged>();

	Action->OwningASC = AbilitySystemComponent;
	Action->CooldownTag = CooldownTag;
		 
	checkf(Action->OwningASC, TEXT("UAsyncAction_CooldownChanged Requires A Valid AbilitySystemComponent In Order To Function Properly"));
	checkf(CooldownTag.IsValid(), TEXT("UAsyncAction_CooldownChanged Requires A Valid Cooldown GameplayTag In Order To Function Properly"));

	AbilitySystemComponent->RegisterGameplayTagEvent(CooldownTag, EGameplayTagEventType::AnyCountChange).AddUObject(Action, &UAsyncAction_CooldownChanged::OnCooldownTagCountChanged);

	return Action;
}

void UAsyncAction_CooldownChanged::EndTask()
{
	if (IsValid(OwningASC))
	{
		OwningASC->RegisterGameplayTagEvent(CooldownTag, EGameplayTagEventType::AnyCountChange).RemoveAll(this);
	}

	SetReadyToDestroy();
	MarkAsGarbage();
}

float UAsyncAction_CooldownChanged::GetRemainingTime() const
{
	return  UCommonAbilityFunctionLibrary::GetMaximumEffectCooldownRemainingForTag(CooldownTag, OwningASC);
}

void UAsyncAction_CooldownChanged::OnCooldownTagCountChanged(const FGameplayTag Tag, int32 TagCount) const
{
	if (TagCount >= 1)
	{
		OnCooldownStart.Broadcast();
	}

	else
	{
		OnCooldownEnd.Broadcast();
	}
}
