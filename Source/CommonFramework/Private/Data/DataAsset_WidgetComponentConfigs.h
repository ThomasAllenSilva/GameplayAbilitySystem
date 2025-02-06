// Thomas Learning Project

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Components/WidgetComponent.h"
#include "DataAsset_WidgetComponentConfigs.generated.h"

#define PROPERTY_ACCESSOR(PropertyType, PropertyName) \
public: \
    FORCEINLINE PropertyType Get##PropertyName() const { return PropertyName; } \

/**
 *
 */
UCLASS()
class COMMONFRAMEWORK_API UDataAsset_WidgetComponentConfigs final : public UDataAsset
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly)
	TEnumAsByte<EWidgetSpace> WidgetSpace = EWidgetSpace::Screen;
	PROPERTY_ACCESSOR(EWidgetSpace, WidgetSpace)

	UPROPERTY(EditDefaultsOnly)
	TEnumAsByte<ETickMode> TickMode = ETickMode::Automatic;
	PROPERTY_ACCESSOR(ETickMode, TickMode)

	UPROPERTY(EditDefaultsOnly)
	FVector2D  DrawSize = FVector2D(250.0f, 250.0f);
	PROPERTY_ACCESSOR(FVector2D, DrawSize)

	UPROPERTY(EditDefaultsOnly)
	bool  bDrawAtDesiredSize = false;
	PROPERTY_ACCESSOR(bool, bDrawAtDesiredSize)

	UPROPERTY(EditDefaultsOnly)
	FVector2D  Pivot = FVector2D(0.5f, 0.5f);
	PROPERTY_ACCESSOR(FVector2D, Pivot)

	UPROPERTY(EditDefaultsOnly)
	FVector  RelativeLocation;
	PROPERTY_ACCESSOR(FVector, RelativeLocation)

	UPROPERTY(EditDefaultsOnly)
	FRotator  RelativeRotation;
	PROPERTY_ACCESSOR(FRotator, RelativeRotation)

	UPROPERTY(EditDefaultsOnly)
	bool bGenerateOverlapEvents;
	PROPERTY_ACCESSOR(bool, bGenerateOverlapEvents)

	UPROPERTY(EditDefaultsOnly)
	TEnumAsByte<ECollisionEnabled::Type> CollisionEnabled = ECollisionEnabled::NoCollision;
	PROPERTY_ACCESSOR(ECollisionEnabled::Type, CollisionEnabled)

	UPROPERTY(EditDefaultsOnly)
	TEnumAsByte<ECollisionResponse> CollisionResponse = ECollisionResponse::ECR_Ignore;
	PROPERTY_ACCESSOR(ECollisionResponse, CollisionResponse)
};
