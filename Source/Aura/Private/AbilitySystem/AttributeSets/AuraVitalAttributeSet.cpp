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
	bool bFound = false;

	const int EnemyLevel = Killer->GetGameplayAttributeValue(UAuraExperienceAttributeSet::GetLevelAttribute(), bFound);

	if (bFound == false)
	{
		return; //The killer doesn't have the Experience AttributeSet, hence, doesn't need an event
	}

	UCommonAbilitySystemComponent* OwningASC = UCommonAbilityFunctionLibrary::GetCommonAbilitySystemComponentFromASC(GetOwningAbilitySystemComponentChecked());

	const FGameplayTag& EnemyTag = OwningASC->GetTagID();

	int XPReward = UAuraFunctionLibrary::GetXPRewardForEnemy(Killer, EnemyTag, EnemyLevel);

	FGameplayEventData EventPayload;
	EventPayload.Target = Killer->GetOwnerActor();
	EventPayload.EventTag = Attributes_Experience_IncomingXP;
	EventPayload.EventMagnitude = XPReward;

	UCommonAbilityFunctionLibrary::SendGameplayEventToActor(Killer->GetOwnerActor(), Attributes_Experience_IncomingXP, EventPayload);
}
