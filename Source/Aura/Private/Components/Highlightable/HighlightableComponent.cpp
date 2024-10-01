#include "Components/Highlightable/HighlightableComponent.h"

UHighlightableComponent::UHighlightableComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

	PrimaryComponentTick.bStartWithTickEnabled = false;

	PrimaryComponentTick.bAllowTickOnDedicatedServer = false;
}

void UHighlightableComponent::BeginPlay()
{
	Super::BeginPlay();

	Owner = GetOwner();

	Owner->OnBeginCursorOver.AddDynamic(this, &UHighlightableComponent::OnBeginCursorOver);

	Owner->OnEndCursorOver.AddDynamic(this, &UHighlightableComponent::OnEndCursorOver);

	InitializeHighlightableMeshs();
}

void UHighlightableComponent::BeginDestroy()
{
	Super::BeginDestroy();

	if (Owner)
	{
		Owner->OnBeginCursorOver.RemoveDynamic(this, &UHighlightableComponent::OnBeginCursorOver);

		Owner->OnEndCursorOver.RemoveDynamic(this, &UHighlightableComponent::OnEndCursorOver);
	}
}

void UHighlightableComponent::OnBeginCursorOver(AActor* TouchedActor)
{
	for (UMeshComponent* HighlightableMesh : HighlightableMeshs)
	{
		HighlightableMesh->SetRenderCustomDepth(true);
	}
}

void UHighlightableComponent::OnEndCursorOver(AActor* TouchedActor)
{
	for (UMeshComponent* HighlightableMesh : HighlightableMeshs)
	{
		HighlightableMesh->SetRenderCustomDepth(false);
	}
}

void UHighlightableComponent::InitializeHighlightableMeshs()
{
	TArray<UMeshComponent*> Components;

	Owner->GetComponents<UMeshComponent>(Components, true);

	for (UMeshComponent* MeshComponent : Components)
	{
		MeshComponent->SetCollisionResponseToChannel(ECC_Visibility, ECollisionResponse::ECR_Block);

		MeshComponent->SetCustomDepthStencilValue(HighlightColor);

		HighlightableMeshs.Add(MeshComponent);
	}
}
