// Thomas Learning Project

#pragma once

#include "CoreMinimal.h"
#include "Characters/Base/AuraCharacterBase.h"
#include "AuraPlayerCharacter.generated.h"

/**
 * 
 */
UCLASS()
class AAuraPlayerCharacter final : public AAuraCharacterBase
{
	GENERATED_BODY()

protected:
	virtual void PossessedBy(AController* NewController) override;

	
};
