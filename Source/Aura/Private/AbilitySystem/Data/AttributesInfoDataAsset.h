// Thomas Learning Project

#pragma once

#include "CoreMinimal.h"

#include "Engine/DataAsset.h"

#include "GameplayTagContainer.h"

#include "AttributeSet.h"

#include "AttributesInfoDataAsset.generated.h"

USTRUCT(BlueprintType)
struct FAuraAttributeInfo
{
	GENERATED_BODY()
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FGameplayAttribute AssociatedAttribute;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FName Description;
};

UCLASS()
class UAttributesInfoDataAsset final : public UDataAsset
{
	GENERATED_BODY()
	
public:
	FAuraAttributeInfo GetAttributeInfo(const FGameplayTag& AttributeTag) const;

private:
	UPROPERTY(EditDefaultsOnly)
	TMap<FGameplayTag, FAuraAttributeInfo> AttributesInfos;
};
