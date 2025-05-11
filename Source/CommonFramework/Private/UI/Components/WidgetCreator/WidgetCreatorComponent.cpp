// Thomas Learning Project

#include "UI/Components/WidgetCreator/WidgetCreatorComponent.h"
#include "Blueprint/UserWidget.h"
#include "UI/Base/ContextualUserWidget.h"
#include "Data/DataAsset_WidgetDefinitions.h"
#include "Data/DataAsset_WidgetComponentConfigs.h"
#include "Components/WidgetComponent.h"
#include "UI/Subsystem/CommonHUDSubsystem.h"
#include "UI/Widgets/HUDLayoutUserWidget.h"

UWidgetCreatorComponent::UWidgetCreatorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

	PrimaryComponentTick.bStartWithTickEnabled = false;

	PrimaryComponentTick.bAllowTickOnDedicatedServer = false;
}

void UWidgetCreatorComponent::CreateDefaultWidgets()
{
	for (const UDataAsset_WidgetDefinitions* WidgetDefinition : WidgetDefinitions)
	{
		if (WidgetDefinition == nullptr)
		{
			continue;
		}

		for (const FWidgetSetupSettings& WidgetSetupSettings : WidgetDefinition->GetStartupWidgets())
		{
			if (WidgetSetupSettings.Widget == nullptr)
			{
				return;
			}

			ConstructWidgetUsingSettings(WidgetSetupSettings);
		}
	}
}

UUserWidget* UWidgetCreatorComponent::ConstructWidgetUsingSettings(const FWidgetSetupSettings& WidgetSetupSettings)
{
	UWorld* World = GetWorld();

	ULocalPlayer* LocalPlayer = World->GetFirstLocalPlayerFromController();

	APlayerController* PlayerController = LocalPlayer->GetPlayerController(World);

	UUserWidget* WidgetInstance = CreateWidget<UUserWidget>(PlayerController, WidgetSetupSettings.Widget);

	check(WidgetInstance);

	AActor* OwningActor = GetOwner();

	if (WidgetSetupSettings.WidgetCreationType == EWidgetCreationType::AddToViewport)
	{
		WidgetInstance->AddToViewport();

		UCommonHUDSubsystem* CommonHUDSubsystem = ULocalPlayer::GetSubsystem<UCommonHUDSubsystem>(LocalPlayer);

		FWidgetContentInfo WidgetContentInfo(WidgetSetupSettings.WidgetTag, WidgetInstance);

		CommonHUDSubsystem->PushToOverlayLayer(WidgetSetupSettings.OverlayLayerTag, WidgetContentInfo);
	}

	else
	{
		UDataAsset_WidgetComponentConfigs* ComponentSettings = WidgetSetupSettings.WidgetComponentSettings;

		UWidgetComponent* WidgetComponent = NewObject<UWidgetComponent>(OwningActor);

		WidgetComponent->SetupAttachment(OwningActor->GetRootComponent());

		WidgetComponent->RegisterComponent();

		WidgetComponent->SetWidget(WidgetInstance);

		WidgetComponent->SetWidgetSpace(ComponentSettings->GetWidgetSpace());

		WidgetComponent->SetTickMode(ComponentSettings->GetTickMode());

		WidgetComponent->SetDrawSize(ComponentSettings->GetDrawSize());

		WidgetComponent->SetDrawAtDesiredSize(ComponentSettings->bDrawAtDesiredSize);

		WidgetComponent->SetPivot(ComponentSettings->GetPivot());

		WidgetComponent->SetRelativeLocation(ComponentSettings->GetRelativeLocation());

		WidgetComponent->SetRelativeRotation(ComponentSettings->GetRelativeRotation());

		WidgetComponent->SetCollisionEnabled(ComponentSettings->CollisionEnabled);

		WidgetComponent->SetGenerateOverlapEvents(ComponentSettings->bGenerateOverlapEvents);

		WidgetComponent->SetCollisionResponseToAllChannels(ComponentSettings->CollisionResponse);
	}

	if (UContextualUserWidget* ContextObject = Cast<UContextualUserWidget>(WidgetInstance))
	{
		ContextObject->SetOwningActor(OwningActor);
	}

	return WidgetInstance;
}

TSubclassOf<UUserWidget> UWidgetCreatorComponent::GetWidgetByTagChecked(const FGameplayTag WidgetTag) const
{
	TSubclassOf<UUserWidget> Widget = nullptr;

	for (const UDataAsset_WidgetDefinitions* WidgetDefinition : WidgetDefinitions)
	{
		bool bFound = false;

		const FWidgetSetupSettings* WidgetSetupSettings = WidgetDefinition->GetWidgetSettingsByTag(WidgetTag, bFound);

		if (bFound)
		{
			Widget = WidgetSetupSettings->Widget;

			break;
		}
	}

	checkf(Widget, TEXT("Could not find widget for the tag: %s"), *WidgetTag.ToString());

	return Widget;
}
