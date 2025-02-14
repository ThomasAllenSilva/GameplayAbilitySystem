// Thomas Learning Project


#include "AuraPickupMessageUserWidget.h"

#include "CommonAbilityFunctionLibrary.h"

#include "Components/CommonAbilitySystemComponent.h"

void UAuraPickupMessageUserWidget::NativeConstruct()
{
	Super::NativeConstruct();

	UCommonAbilitySystemComponent* PlayerASC = UCommonAbilityFunctionLibrary::GetLocalPlayerAbilitySystemComponent(this);

	EffectAppliedDelegateHandle = PlayerASC->OnGameplayEffectAppliedDelegateToSelf.AddUObject(this, &UAuraPickupMessageUserWidget::OnGameplayEffectAppliedDelegateToSelf);
}

void UAuraPickupMessageUserWidget::BeginDestroy()
{
	Super::BeginDestroy();

	UCommonAbilitySystemComponent* PlayerASC = UCommonAbilityFunctionLibrary::GetLocalPlayerAbilitySystemComponent(this);

	if (IsValid(PlayerASC))
	{
		PlayerASC->OnGameplayEffectAppliedDelegateToSelf.Remove(EffectAppliedDelegateHandle);
	}
}

void UAuraPickupMessageUserWidget::OnGameplayEffectAppliedDelegateToSelf(UAbilitySystemComponent* ASC, const FGameplayEffectSpec& EffectSpec, FActiveGameplayEffectHandle EffectHandle)
{
	FGameplayTagContainer TagsContainer;

	EffectSpec.GetAllAssetTags(TagsContainer);

	for (const FGameplayTag& Tag : TagsContainer)
	{
		if (Tag.MatchesTag(MessageTag))
		{
			OnRequestedPickupMessage(Tag);
		}
	}
}
