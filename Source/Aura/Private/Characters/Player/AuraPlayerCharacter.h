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

	//~ Begin AbilitySystem Interface
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	//~ End of AbilitySystem Interface

protected:
	virtual void PossessedBy(AController* NewController) override;

private:
	UPROPERTY(BlueprintReadOnly, meta = (AllowPrivateAccess))
	TObjectPtr<UCommonAbilitySystemComponent> AbilitySystemComponent;
};
