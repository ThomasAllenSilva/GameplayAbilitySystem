// Thomas Learning Project

#include "AbilitySystem/Ability/Base/AuraGameplayAbility.h"
#include "Characters/Base/AuraCharacterBase.h"

void UAuraGameplayAbility::OnGiveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec)
{
    Super::OnGiveAbility(ActorInfo, Spec);

    check(ActorInfo->AvatarActor.Get());

    OwnerAuraCharacter = CastChecked<AAuraCharacterBase>(ActorInfo->AvatarActor.Get());
}

void UAuraGameplayAbility::OnRemoveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec)
{
    Super::OnRemoveAbility(ActorInfo, Spec);

    OwnerAuraCharacter.Reset();
}

AAuraCharacterBase* UAuraGameplayAbility::GetAuraCharacterFromActorInfo() const
{
    check(OwnerAuraCharacter.Get());

    return OwnerAuraCharacter.Get();
}
