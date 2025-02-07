#pragma once

#include "GameplayEffectTypes.h"

#include "AuraEffectTypes.generated.h"

USTRUCT(BlueprintType)
struct FAuraDamageEffectContext final : public FGameplayEffectContext
{
	GENERATED_BODY()
};
