// Thomas Learning Project

#include "WidgetCreatorComponent.h"

#include "Blueprint/UserWidget.h"

#include "WidgetComponentSettings.h"

#include "UI/Base/ContextualUserWidget.h"

#include "Components/WidgetComponent.h"

UWidgetCreatorComponent::UWidgetCreatorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

	PrimaryComponentTick.bStartWithTickEnabled = false;

	PrimaryComponentTick.bAllowTickOnDedicatedServer = false;
}

void UWidgetCreatorComponent::BeginPlay()
{
	Super::BeginPlay();

	CreateStartupWidgets();
}

void UWidgetCreatorComponent::CreateStartupWidgets()
{
	for (FActorWidgets& WidgetTemplate : StartupWidgets)
	{
		if (WidgetTemplate.Widget == nullptr)
		{
			return;
		}

		UWorld* World = GetWorld();

		ULocalPlayer* LocalPlayer = World->GetFirstLocalPlayerFromController();

		APlayerController* PlayerController = LocalPlayer->GetPlayerController(World);

		UUserWidget* WidgetInstance = CreateWidget<UUserWidget>(PlayerController, WidgetTemplate.Widget);

		AActor* OwningActor = GetOwner();

		if (WidgetTemplate.WidgetCreationType == EWidgetCreationType::AddToViewport)
		{
			WidgetInstance->AddToViewport();
		}

		else
		{
			UWidgetComponentSettings* ComponentSettings = WidgetTemplate.WidgetComponentSettings;

			UWidgetComponent* WidgetComponent = NewObject<UWidgetComponent>(OwningActor);

			WidgetComponent->SetupAttachment(OwningActor->GetRootComponent());

			WidgetComponent->RegisterComponent();

			WidgetComponent->SetWidgetClass(WidgetTemplate.Widget);

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
	}
}
