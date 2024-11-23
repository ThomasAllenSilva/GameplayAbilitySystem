// Thomas Learning Project


#include "AuraPickupMessageUserWidget.h"

#include "AuraBlueprintFunctionLibrary.h"

#include "AbilitySystem/Component/AuraAbilitySystemComponent.h"

void UAuraPickupMessageUserWidget::NativeConstruct()
{
	Super::NativeConstruct();

	UAuraAbilitySystemComponent* PlayerASC = UAuraBlueprintFunctionLibrary::GetLocalPlayerAbilitySystemComponent(this);

	GameplayEffectAppliedHandle = PlayerASC->OnGameplayEffectAppliedDelegateToSelf.AddUObject(this, &UAuraPickupMessageUserWidget::OnGameplayEffectAppliedDelegateToSelf);
}

void UAuraPickupMessageUserWidget::BeginDestroy()
{
	Super::BeginDestroy();

	UAuraAbilitySystemComponent* PlayerASC = UAuraBlueprintFunctionLibrary::GetLocalPlayerAbilitySystemComponent(this);

	if (IsValid(PlayerASC))
	{
		PlayerASC->OnGameplayEffectAppliedDelegateToSelf.Remove(GameplayEffectAppliedHandle);
	}
}

void UAuraPickupMessageUserWidget::OnGameplayEffectAppliedDelegateToSelf(UAbilitySystemComponent* ASC, const FGameplayEffectSpec& EffectSpec, FActiveGameplayEffectHandle EffectHandle)
{
	FGameplayTagContainer TagsContainer;

	EffectSpec.GetAllAssetTags(TagsContainer);

	for (const FGameplayTag& Tag : TagsContainer)
	{
		if (MessageTag.MatchesTag(MessageTag))
		{
			OnRequestedPickupMessage(Tag);
		}
	}
}
