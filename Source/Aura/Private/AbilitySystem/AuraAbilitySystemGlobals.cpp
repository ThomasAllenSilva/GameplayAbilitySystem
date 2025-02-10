// Thomas Learning Project


#include "AbilitySystem/AuraAbilitySystemGlobals.h"
#include "Types/AuraEffectTypes.h"

FGameplayEffectContext* UAuraAbilitySystemGlobals::AllocGameplayEffectContext() const
{
    return new FAuraGameplayEffectContext();
}
