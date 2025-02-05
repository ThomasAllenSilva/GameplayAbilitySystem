// Thomas Hero Project


#include "Data/DataAsset_CommonAbilitySet.h"
#include "Ability/CommonGameplayAbility.h"
#include "Components/CommonAbilitySystemComponent.h"

void UDataAsset_CommonAbilitySet::GiveToAbilitySystem(UCommonAbilitySystemComponent* InASC) const
{
	check(InASC);

	if (InASC->IsOwnerActorAuthoritative() == false)
	{
		// Must be authoritative to give or take ability sets.
		return;
	}

	// Grant the attribute sets.
	for (int32 SetIndex = 0; SetIndex < GrantedAttributes.Num(); ++SetIndex)
	{
		TSubclassOf<UAttributeSet> SetToGrant = GrantedAttributes[SetIndex];

		if (!IsValid(SetToGrant))
		{
			UE_LOG(LogTemp, Error, TEXT("GrantedAttributes[%d] on ability set [%s] is not valid"), SetIndex, *GetNameSafe(this));

			continue;
		}

		UAttributeSet* NewSet = NewObject<UAttributeSet>(InASC->GetOwner(), SetToGrant);

		InASC->AddAttributeSetSubobject(NewSet);
	}

	// Grant the gameplay abilities.
	for (int32 AbilityIndex = 0; AbilityIndex < GrantedGameplayAbilities.Num(); ++AbilityIndex)
	{
		const FCommonAbilitySet_GameplayAbility& AbilityToGrant = GrantedGameplayAbilities[AbilityIndex];

		if (!IsValid(AbilityToGrant.Ability))
		{
			UE_LOG(LogTemp, Error, TEXT("GrantedGameplayAbilities[%d] on ability set [%s] is not valid."), AbilityIndex, *GetNameSafe(this));

			continue;
		}

		FGameplayAbilitySpec AbilitySpec(AbilityToGrant.Ability, AbilityToGrant.AbilityLevel);

		AbilitySpec.SourceObject = InASC;

		AbilitySpec.DynamicAbilityTags.AddTag(AbilityToGrant.InputTag);

		InASC->GiveAbility(AbilitySpec);
	}

	// Grant the gameplay effects.
	for (int32 EffectIndex = 0; EffectIndex < GrantedGameplayEffects.Num(); ++EffectIndex)
	{
		const FCommonAbilitySet_GameplayEffect& EffectToGrant = GrantedGameplayEffects[EffectIndex];

		if (!IsValid(EffectToGrant.GameplayEffect))
		{
			UE_LOG(LogTemp, Error, TEXT("GrantedGameplayEffects[%d] on ability set [%s] is not valid"), EffectIndex, *GetNameSafe(this));

			continue;
		}

		const UGameplayEffect* GameplayEffect = EffectToGrant.GameplayEffect->GetDefaultObject<UGameplayEffect>();
		InASC->ApplyGameplayEffectToSelf(GameplayEffect, EffectToGrant.EffectLevel, InASC->MakeEffectContext());
	}
}
