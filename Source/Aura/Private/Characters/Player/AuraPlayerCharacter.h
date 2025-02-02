// Thomas Learning Project

#pragma once

#include "CoreMinimal.h"
#include "Characters/Base/AuraCharacterBase.h"
#include "AuraPlayerCharacter.generated.h"

class UCommonAbilitySystemComponent;

/**
 * 
 */
UCLASS()
class AAuraPlayerCharacter final : public AAuraCharacterBase
{
	GENERATED_BODY()

public:
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

protected:
	virtual void PossessedBy(AController* NewController) override;
	
private:
	UPROPERTY(BlueprintReadOnly, meta = (AllowPrivateAccess))
	TObjectPtr<UCommonAbilitySystemComponent> AbilitySystemComponent;
};
