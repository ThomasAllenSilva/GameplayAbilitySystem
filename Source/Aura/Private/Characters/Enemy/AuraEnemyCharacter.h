// Thomas Learning Project

#pragma once

#include "CoreMinimal.h"

#include "Characters/Base/AuraCharacterBase.h"

#include "AuraEnemyCharacter.generated.h"

class UCommonAbilitySystemComponent;

UCLASS()
class AAuraEnemyCharacter final : public AAuraCharacterBase
{
	GENERATED_BODY()

public:
	AAuraEnemyCharacter();

public:
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

protected:
	virtual void BeginPlay() override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TObjectPtr<UCommonAbilitySystemComponent> AbilitySystemComponent;
};
