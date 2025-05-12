// Thomas Learning Project


#include "AuraFunctionLibrary.h"
#include "GameMode/AuraGameMode.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystem/AttributeSets/AuraUpgradePointsAttributeSet.h"
#include "CommonAbilityFunctionLibrary.h"

int UAuraFunctionLibrary::GetXPRewardForEnemy(const UObject* WorldContextObject, const FGameplayTag& EnemyTag, const int EnemyLevel)
{
	UWorld* const World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull);

	checkf(World, TEXT("Cannot retrieve game mode from null world"));

	const AAuraGameMode* AuraGameMode = World->GetAuthGameMode<AAuraGameMode>();

	return AuraGameMode->GetXPRewardForEnemy(EnemyTag, EnemyLevel);
}

FVector UAuraFunctionLibrary::GetCursorWorldLocation(const UObject* WorldContextObject)
{
	const UWorld* World = WorldContextObject->GetWorld();

	const ULocalPlayer* LocalPlayer = World->GetFirstLocalPlayerFromController();

	const APlayerController* PlayerController = LocalPlayer->GetPlayerController(World);

	FVector WorldLocation;
	FVector WorldDirection;

	PlayerController->DeprojectMousePositionToWorld(WorldLocation, WorldDirection);

	FHitResult HitResult;

	const FVector EndTraceLocation = ( WorldDirection) * UE_MAX_FLT;

	World->LineTraceSingleByChannel(HitResult, WorldLocation, EndTraceLocation, ECollisionChannel::ECC_Visibility);

	return HitResult.ImpactPoint;
}

void UAuraFunctionLibrary::UpgradeAttribute(UAbilitySystemComponent* AbilitySystemComponent, const FGameplayAttribute Attribute, const float UpgradeMagnitude)
{
	FGameplayAttribute UpgradeAttribute = UAuraUpgradePointsAttributeSet::GetAttributePointsAttribute();

	UGameplayEffect* UpgradeEffect = NewObject<UGameplayEffect>();

	// Modifier used to upgrade the target attribute
	FGameplayModifierInfo ModifierInfo_AttributeUpgrade = FGameplayModifierInfo();
	FScalableFloat Magnitude_AttributeUpgrader = FScalableFloat(UpgradeMagnitude);
	ModifierInfo_AttributeUpgrade.Attribute = Attribute;
	ModifierInfo_AttributeUpgrade.ModifierMagnitude = FGameplayEffectModifierMagnitude(Magnitude_AttributeUpgrader);


	// Modifier used to reduce the attribute upgrade points
	FGameplayModifierInfo ModifierInfo_PointReducer = FGameplayModifierInfo();
	FScalableFloat Magnitude_PointReducer = FScalableFloat(-UpgradeMagnitude);
	ModifierInfo_PointReducer.Attribute = UpgradeAttribute;
	ModifierInfo_PointReducer.ModifierMagnitude = FGameplayEffectModifierMagnitude(Magnitude_PointReducer);

	UpgradeEffect->Modifiers.Add(ModifierInfo_AttributeUpgrade);
	UpgradeEffect->Modifiers.Add(ModifierInfo_PointReducer);

	FGameplayEffectContextHandle EffectContextHandle = AbilitySystemComponent->MakeEffectContext();

	FGameplayEffectSpec EffectSpec = FGameplayEffectSpec(UpgradeEffect, EffectContextHandle);

	AbilitySystemComponent->ApplyGameplayEffectSpecToSelf(EffectSpec);
}
