// Thomas Learning Project

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "Components/CommonAbilitySystemComponent.h"
#include "AuraVitalAttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

UCLASS()
class UAuraVitalAttributeSet final : public UAttributeSet
{
	GENERATED_BODY()

public:
	virtual void PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data) override;

public:

	ATTRIBUTE_ACCESSORS(UAuraVitalAttributeSet, Health);
	ATTRIBUTE_ACCESSORS(UAuraVitalAttributeSet, MaxHealth);
	ATTRIBUTE_ACCESSORS(UAuraVitalAttributeSet, Mana);
	ATTRIBUTE_ACCESSORS(UAuraVitalAttributeSet, MaxMana);
	ATTRIBUTE_ACCESSORS(UAuraVitalAttributeSet, IncomingDamage);

private:
	/* Used to reward XP to whoever killed the owner of this attribute set. */
	void SendXPEventToKiller(UAbilitySystemComponent* Killer);

private:
	UPROPERTY(BlueprintReadOnly, Category = "Vital Attributes", meta = (AllowPrivateAccess))
	FGameplayAttributeData Health;

	UPROPERTY(BlueprintReadOnly, Category = "Vital Attributes", meta = (AllowPrivateAccess))
	FGameplayAttributeData MaxHealth;

	UPROPERTY(BlueprintReadOnly, Category = "Vital Attributes", meta = (AllowPrivateAccess))
	FGameplayAttributeData Mana;

	UPROPERTY(BlueprintReadOnly, Category = "Vital Attributes", meta = (AllowPrivateAccess))
	FGameplayAttributeData MaxMana;

	// The base amount of damage to apply in the damage execution. This is mapped directly to -Health
	UPROPERTY(BlueprintReadOnly, Category = "Vital Meta Attributes", meta = (AllowPrivateAccess))
	FGameplayAttributeData IncomingDamage;
};
