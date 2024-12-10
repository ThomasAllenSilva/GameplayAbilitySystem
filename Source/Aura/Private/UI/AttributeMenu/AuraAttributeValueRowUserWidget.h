// Thomas Learning Project

#pragma once

#include "CoreMinimal.h"

#include "Blueprint/UserWidget.h"

#include "GameplayTagContainer.h"

#include "AuraAttributeValueRowUserWidget.generated.h"

class UAttributesInfoDataAsset;

struct FOnAttributeChangeData;

UCLASS()
class UAuraAttributeValueRowUserWidget final : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;

	UFUNCTION(BlueprintImplementableEvent)
	void OnAttributeValueChanged(float NewValue);

private:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (AllowPrivateAccess))
	TObjectPtr<UAttributesInfoDataAsset> AttributeInfoData;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, meta = (AllowPrivateAccess))
	FGameplayTag AssociatedTag;
};
