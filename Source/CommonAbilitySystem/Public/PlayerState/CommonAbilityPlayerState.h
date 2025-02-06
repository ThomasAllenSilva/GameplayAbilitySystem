// Thomas Hero Project

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "AbilitySystemInterface.h"
#include "CommonAbilityPlayerState.generated.h"

class UCommonAbilitySystemComponent;

/**
 * 
 */
UCLASS()
class COMMONABILITYSYSTEM_API ACommonAbilityPlayerState : public APlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()
	
public:
	ACommonAbilityPlayerState();

	virtual void BeginPlay() override;

	//~ Begin AbilitySystem Interface
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	//~ End AbilitySystem Interface

private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess))
	TObjectPtr<UCommonAbilitySystemComponent> AbilitySystemComponent;
};
