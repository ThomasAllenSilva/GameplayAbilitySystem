// Thomas Learning Project

#pragma once

#include "CoreMinimal.h"

#include "GameFramework/Actor.h"

#include "AuraEffectActor.generated.h"

UCLASS()
class AAuraEffectActor final : public AActor
{
	GENERATED_BODY()
	
public:	
	AAuraEffectActor();

protected:
	UFUNCTION(BlueprintCallable)
	void ApplyEffectToActor(const AActor* Target, TSubclassOf<UGameplayEffect> EffectToApply);

private:
	UPROPERTY(EditDefaultsOnly, meta = (AllowPrivateAccess = "true"))
	TSubclassOf<UGameplayEffect> Effect;
};
