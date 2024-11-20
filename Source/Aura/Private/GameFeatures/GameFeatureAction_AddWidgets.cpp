// Thomas Learning Project

#include "GameFeatures/GameFeatureAction_AddWidgets.h"

#include "Components/GameFrameworkComponentManager.h"

#include "UI/HUD/AuraHUD.h"

void UGameFeatureAction_AddWidgets::OnGameFeatureActivating(FGameFeatureActivatingContext& Context)
{
	GameInstanceStartHandles.FindOrAdd(Context) = FWorldDelegates::OnStartGameInstance.AddUObject(this,
		&UGameFeatureAction_AddWidgets::HandleGameInstanceStart, FGameFeatureStateChangeContext(Context));

	for (const FWorldContext& WorldContext : GEngine->GetWorldContexts())
	{
		if (Context.ShouldApplyToWorldContext(WorldContext))
		{
			AddToWorld(WorldContext, Context);
		}
	}
}

void UGameFeatureAction_AddWidgets::OnGameFeatureDeactivating(FGameFeatureDeactivatingContext& Context)
{
	FDelegateHandle* FoundHandle = GameInstanceStartHandles.Find(Context);

	if (ensure(FoundHandle))
	{
		FWorldDelegates::OnStartGameInstance.Remove(*FoundHandle);
	}
}

void UGameFeatureAction_AddWidgets::HandleGameInstanceStart(UGameInstance* GameInstance, FGameFeatureStateChangeContext ChangeContext)
{
	if (FWorldContext* WorldContext = GameInstance->GetWorldContext())
	{
		if (ChangeContext.ShouldApplyToWorldContext(*WorldContext))
		{
			AddToWorld(*WorldContext, ChangeContext);
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
			ComponentManager->AddExtensionHandler(AAuraHUD::StaticClass(), UGameFrameworkComponentManager::FExtensionHandlerDelegate::CreateUObject(this, &UGameFeatureAction_AddWidgets::HandleActorExtension, ChangeContext));
		}
	}
}

void UGameFeatureAction_AddWidgets::HandleActorExtension(AActor* Actor, FName EventName, FGameFeatureStateChangeContext ChangeContext)
{
	if ((EventName == UGameFrameworkComponentManager::NAME_ExtensionRemoved) || (EventName == UGameFrameworkComponentManager::NAME_ReceiverRemoved))
	{
		RemoveWidgets();
	}
	else if ((EventName == UGameFrameworkComponentManager::NAME_ExtensionAdded) || (EventName == UGameFrameworkComponentManager::NAME_GameActorReady))
	{
		CreateWidgets();
	}
}

void UGameFeatureAction_AddWidgets::CreateWidgets()
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 3, FColor::Green, TEXT("Creating Widgets"));
	}

	UE_LOG(LogTemp, Warning, TEXT("Creating Widgets"));
}

void UGameFeatureAction_AddWidgets::RemoveWidgets()
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 3, FColor::Green, TEXT("Removing Widgets"));
	}

	UE_LOG(LogTemp, Warning, TEXT("Removing Widgets"));
}
