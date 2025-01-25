#pragma once

#include "CoreMinimal.h"

#include "Components/ActorComponent.h"

#include "HighlightableComponent.generated.h"

UENUM()
enum EDepthStencilValue
{
	Red = 250,
};

/*
* 
*/
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class AURA_API UHighlightableComponent final : public UActorComponent
{
	GENERATED_BODY()

public:
	UHighlightableComponent();

protected:
	virtual void BeginPlay() override;

	virtual void BeginDestroy() override;

private:
	UPROPERTY()
	TObjectPtr<AActor> Owner;

	UPROPERTY()
	TArray<TObjectPtr<UMeshComponent>> HighlightableMeshs;

	UPROPERTY(EditAnywhere)
	TEnumAsByte<EDepthStencilValue> HighlightColor = EDepthStencilValue::Red;

private:
	/*Triggered when the mouse is over the owner of this component. Used to highlight the meshes*/
	UFUNCTION()
	void OnBeginCursorOver(AActor* TouchedActor);

	/*Used to remove highlights from meshes when the cursor stops hovering over the owning actor*/
	UFUNCTION()
	void OnEndCursorOver(AActor* TouchedActor);

	void InitializeHighlightableMeshs();
};
