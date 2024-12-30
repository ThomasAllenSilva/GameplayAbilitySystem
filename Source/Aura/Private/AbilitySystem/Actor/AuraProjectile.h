// Thomas Learning Project

#pragma once

#include "CoreMinimal.h"

#include "GameFramework/Actor.h"

#include "GameplayEffectTypes.h"

#include "AuraProjectile.generated.h"

class UProjectileMovementComponent;

class UNiagaraSystem;

class USoundBase;

UCLASS()
class AAuraProjectile final : public AActor
{
	GENERATED_BODY()

public:
	AAuraProjectile();

	UFUNCTION(BlueprintCallable, Category = "Projectile", meta = (HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	static const AAuraProjectile* CreateProjectile(const UObject* WorldContextObject, TSubclassOf<AAuraProjectile> ProjectileClass, AActor* OwningActor, const FVector& TargetLocation, const FGameplayEffectSpecHandle& EffectSpecHandle);

protected:
	UFUNCTION(BlueprintCallable)
	void ApplyProjectileEffectToTarget(AActor* OtherActor);

	UFUNCTION(BlueprintCallable)
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UProjectileMovementComponent> ProjectileMovementComponent;

	UPROPERTY(EditDefaultsOnly, Category = "Effects")
	TObjectPtr<UNiagaraSystem> CollisionEffect;

	UPROPERTY(EditDefaultsOnly, Category = "Sounds")
	TObjectPtr<USoundBase> CollisionSound;

	UPROPERTY(EditDefaultsOnly, Category = "Sounds")
	TObjectPtr<USoundBase> AttachedSpawnSound;

	UPROPERTY()
	FGameplayEffectSpecHandle EffectSpecHandle;
};
