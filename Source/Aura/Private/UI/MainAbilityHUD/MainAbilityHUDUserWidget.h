// Thomas Learning Project

#pragma once

#include "CoreMinimal.h"
#include "UI/Base/ContextualUserWidget.h"
#include "MainAbilityHUDUserWidget.generated.h"

class UDataAsset_AbilityInfo;

/**
 * 
 */
UCLASS()
class UMainAbilityHUDUserWidget final : public UContextualUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;

	UFUNCTION(BlueprintImplementableEvent)
	void OnUpdateAbility(const FGameplayTag& AbilityTag, const FGameplayTag& InputTag);

	UFUNCTION(BlueprintCallable)
	FAuraAbilityInfo GetAbilityInfoForAbilityTag(const FGameplayTag& AbilityTag) const;

private:
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UDataAsset_AbilityInfo> AbilitiesInfo;
};
