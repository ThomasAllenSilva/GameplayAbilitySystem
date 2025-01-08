// Thomas Learning Project

#include "WidgetCreatorComponent.h"

#include "Blueprint/UserWidget.h"

#include "WidgetComponentSettings.h"

#include "Data/ContextObject.h"

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
			UWidgetComponent* WidgetComponent = NewObject<UWidgetComponent>(OwningActor);

			WidgetComponent->SetupAttachment(OwningActor->GetRootComponent());

			WidgetComponent->RegisterComponent();

			WidgetComponent->SetWidgetClass(WidgetTemplate.Widget);

			WidgetComponent->SetWidgetSpace(WidgetTemplate.WidgetComponentSettings->GetWidgetSpace());

			WidgetComponent->SetTickMode(WidgetTemplate.WidgetComponentSettings->GetTickMode());

			WidgetComponent->SetDrawSize(WidgetTemplate.WidgetComponentSettings->GetDrawSize());

			WidgetComponent->SetDrawAtDesiredSize(WidgetTemplate.WidgetComponentSettings->bDrawAtDesiredSize);

			WidgetComponent->SetPivot(WidgetTemplate.WidgetComponentSettings->GetPivot());

			WidgetComponent->SetRelativeLocation(WidgetTemplate.WidgetComponentSettings->GetRelativeLocation());

			WidgetComponent->SetRelativeRotation(WidgetTemplate.WidgetComponentSettings->GetRelativeRotation());
		}

		if (UContextObject* ContextObject = Cast<UContextObject>(WidgetInstance))
		{
			ContextObject->SetOwningActor(OwningActor);
		}
	}
}
