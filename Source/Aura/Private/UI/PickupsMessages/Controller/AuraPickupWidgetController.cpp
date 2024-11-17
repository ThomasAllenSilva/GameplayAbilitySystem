// Thomas Learning Project

#include "UI/PickupsMessages/Controller/AuraPickupWidgetController.h"

#include "AbilitySystem/Component/AuraAbilitySystemComponent.h"

void UAuraPickupWidgetController::Initialize(UAuraAbilitySystemComponent* InPlayerASC)
{
	PlayerASC = InPlayerASC;

	PlayerASC->OnGameplayEffectAppliedDelegateToSelf.AddWeakLambda(this,
		[this](UAbilitySystemComponent*, const FGameplayEffectSpec& EffectSpec, FActiveGameplayEffectHandle)
		{
			FGameplayTagContainer TagsContainer;

			FGameplayTag MessageTag = FGameplayTag::RequestGameplayTag("Message");

			EffectSpec.GetAllAssetTags(TagsContainer);

			for (const FGameplayTag& Tag : TagsContainer)
			{
				if (MessageTag.MatchesTag(MessageTag))
				{
					OnRequestedPickupMessage.Broadcast(Tag);
				}
			}
		});
}
