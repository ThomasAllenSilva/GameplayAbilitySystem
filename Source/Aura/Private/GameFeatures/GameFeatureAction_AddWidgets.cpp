// Thomas Learning Project

#include "GameFeatures/GameFeatureAction_AddWidgets.h"

#include "Components/GameFrameworkComponentManager.h"

#include "Blueprint/UserWidget.h"

#include "GameFramework/Actor.h"

void UGameFeatureAction_AddWidgets::OnGameFeatureActivating(FGameFeatureActivatingContext& Context)
{
	for (const FWorldContext& WorldContext : GEngine->GetWorldContexts())
	{
		if (Context.ShouldApplyToWorldContext(WorldContext))
		{
			AddToWorld(WorldContext, Context);
		}
	}
}

void UGameFeatureAction_AddWidgets::AddToWorld(const FWorldContext& WorldContext, const FGameFeatureStateChangeContext& ChangeContext)
{
	UWorld* World = WorldContext.World();

	UGameInstance* GameInstance = WorldContext.OwningGameInstance;

	if ((GameInstance != nullptr) && (World != nullptr) && World->IsGameWorld())
	{
		if (UGameFrameworkComponentManager* ComponentManager = UGameInstance::GetSubsystem<UGameFrameworkComponentManager>(GameInstance))
		{
			Handler = ComponentManager->AddExtensionHandler(ActorExtensionHandler, UGameFrameworkComponentManager::FExtensionHandlerDelegate::CreateUObject(this, &UGameFeatureAction_AddWidgets::HandleActorExtension, ChangeContext));
		}
	}
}

void UGameFeatureAction_AddWidgets::HandleActorExtension(AActor* Actor, FName EventName, FGameFeatureStateChangeContext ChangeContext)
{
	checkf(Actor, TEXT("Actor Extension Is Null"));

	if ((EventName == UGameFrameworkComponentManager::NAME_ExtensionRemoved) || (EventName == UGameFrameworkComponentManager::NAME_ReceiverRemoved))
	{
		RemoveWidgets();
	}

	else if ((EventName == UGameFrameworkComponentManager::NAME_ExtensionAdded) || (EventName == UGameFrameworkComponentManager::NAME_GameActorReady))
	{
		Actor->OnDestroyed.AddDynamic(this, &UGameFeatureAction_AddWidgets::OnDestroyedHandlerActor);

		CreateWidgets(Actor->GetWorld());
	}
}

void UGameFeatureAction_AddWidgets::CreateWidgets(UWorld* World)
{
	checkf(World, TEXT("World is null. Cannot create widgets."));

	for (FGameFeatureWidgetEntry& WidgetEntry : WidgetsList)
	{
		UUserWidget* NewWidget = CreateWidget<UUserWidget>(World, WidgetEntry.WidgetClass);

		NewWidget->AddToViewport();

		CreatedWidgets.Add(NewWidget);
	}
}

void UGameFeatureAction_AddWidgets::RemoveWidgets()
{
	for (UUserWidget* Widget : CreatedWidgets)
	{
		Widget->RemoveFromParent();
	}

	CreatedWidgets.Empty();
}

void UGameFeatureAction_AddWidgets::OnDestroyedHandlerActor(AActor* DestroyedActor)
{
	DestroyedActor->OnDestroyed.RemoveDynamic(this, &UGameFeatureAction_AddWidgets::OnDestroyedHandlerActor);

	Handler.Reset();
}
