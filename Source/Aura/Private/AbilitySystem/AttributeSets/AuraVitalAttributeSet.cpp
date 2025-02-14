// Thomas Learning Project

#include "AuraVitalAttributeSet.h"
#include "GameplayEffectExtension.h"
#include "CommonAbilityFunctionLibrary.h"
#include "AuraNativeGameplayTags.h"

void UAuraVitalAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	if (Data.EvaluatedData.Attribute == GetIncomingDamageAttribute())
	{
		float IncomingDamageMagnitude = GetIncomingDamage();

		float NewHealth = GetHealth() - IncomingDamageMagnitude;

		SetHealth(FMath::Clamp(NewHealth, 0.0f, GetMaxHealth()));

		if (GetHealth() == 0.0f)
		{
			UCommonAbilityFunctionLibrary::AddGameplayTagToActorIfNone(Data.Target.GetAvatarActor(), Common_Status_Dead);
		}

		SetIncomingDamage(0.0f);
	}
}
