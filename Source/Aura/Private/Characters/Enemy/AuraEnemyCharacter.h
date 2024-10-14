// Thomas Learning Project

#pragma once

#include "CoreMinimal.h"

#include "Characters/Base/AuraCharacterBase.h"

#include "AuraEnemyCharacter.generated.h"

UCLASS()
class AAuraEnemyCharacter final : public AAuraCharacterBase
{
	GENERATED_BODY()

public:
	AAuraEnemyCharacter();

protected:
	virtual void BeginPlay() override;
};
