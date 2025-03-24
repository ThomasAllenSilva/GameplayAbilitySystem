#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HighlightableComponent.generated.h"

UENUM()
/* Defines the color values used by the post-processing volume for highlighting */
enum class EDepthStencilValue : uint8
{
	Red = 250,
};

/*
* Allows an actor's meshes to be highlighted using CustomDepth
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

	/*Triggered when the mouse is over the owner of this component. Used to highlight the meshes*/
	UFUNCTION()
	void OnBeginCursorOver(AActor* TouchedActor);

	/*Used to remove highlights from meshes when the cursor stops hovering over the owning actor*/
	UFUNCTION()
	void OnEndCursorOver(AActor* TouchedActor);

	/* Gather all the actor's mesh information and set them up for highlighting */
	void InitializeHighlightableMeshs();

private:

	/* The actor that owns this component */
	UPROPERTY()
	TObjectPtr<AActor> Owner;

	/* All the meshes inside the owning actor */
	UPROPERTY()
	TArray<TObjectPtr<UMeshComponent>> HighlightableMeshs;

	/* The color used to highlight the meshes */
	UPROPERTY(EditAnywhere)
	EDepthStencilValue HighlightColor = EDepthStencilValue::Red;
};
