// Thomas Learning Project

#include "AuraVitalAttributeSet.h"
#include "GameplayEffectExtension.h"
#include "CommonAbilityFunctionLibrary.h"
#include "AuraNativeGameplayTags.h"
#include "AuraFunctionLibrary.h"
#include "Components/CommonAbilitySystemComponent.h"
#include "AbilitySystem/AttributeSets/AuraExperienceAttributeSet.h"

void UAuraVitalAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	bool bFatal = false;
	
	if (Data.EvaluatedData.Attribute == GetIncomingDamageAttribute())
	{
		float IncomingDamageMagnitude = GetIncomingDamage();

		float NewHealth = GetHealth() - IncomingDamageMagnitude;

		SetHealth(FMath::Clamp(NewHealth, 0.0f, GetMaxHealth()));

		SetIncomingDamage(0.0f);
	}

	if (Data.EvaluatedData.Attribute == GetIncomingDamageAttribute() || Data.EvaluatedData.Attribute == GetHealthAttribute())
	{
		if (GetHealth() <= 0.0f)
		{
			//In case we went below zero
			SetHealth(0.0f);

			UCommonAbilityFunctionLibrary::AddGameplayTagToActorIfNone(Data.Target.GetAvatarActor(), Common_Status_Dead);

			bFatal = true;
		}
	}

	if (bFatal)
	{
		UAbilitySystemComponent* KillerASC = Data.EffectSpec.GetEffectContext().GetInstigatorAbilitySystemComponent();

		SendXPEventToKiller(KillerASC);
	}
}

void UAuraVitalAttributeSet::SendXPEventToKiller(UAbilitySystemComponent* Killer)
{
	UCommonAbilitySystemComponent* OwningASC = UCommonAbilityFunctionLibrary::GetCommonAbilitySystemComponentFromASC(GetOwningAbilitySystemComponentChecked());

	bool bFound = false;

	int EnemyLevel = OwningASC->GetGameplayAttributeValue(UAuraExperienceAttributeSet::GetLevelAttribute(), bFound);

	if (bFound == false)
	{
		EnemyLevel = 1; //The enemy doesn't have the Experience AttributeSet, so by default we set to level 1.
	}

	const FGameplayTag& EnemyTag = OwningASC->GetTagID();

	int XPReward = UAuraFunctionLibrary::GetXPRewardForEnemy(Killer, EnemyTag, EnemyLevel);

	FGameplayEventData EventPayload;
	EventPayload.Target = Killer->GetOwnerActor();
	EventPayload.EventTag = Attributes_Experience_IncomingXP;
	EventPayload.EventMagnitude = XPReward;

	UCommonAbilityFunctionLibrary::SendGameplayEventToActor(Killer->GetOwnerActor(), Attributes_Experience_IncomingXP, EventPayload);
}
