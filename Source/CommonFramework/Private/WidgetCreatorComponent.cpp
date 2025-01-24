// Thomas Learning Project

#include "WidgetCreatorComponent.h"

#include "Blueprint/UserWidget.h"

#include "WidgetComponentSettings.h"

#include "UI/Base/ContextualUserWidget.h"

#include "UI/WidgetDefinitions.h"

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
	for (TObjectPtr<UWidgetDefinitions> WidgetDefinition : WidgetDefinitions)
	{
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

UUserWidget* UWidgetCreatorComponent::CreateWidgetByTag(const FGameplayTag& Tag)
{
	UUserWidget* WidgetInstance = nullptr;

	for (TObjectPtr<UWidgetDefinitions> WidgetDefinition : WidgetDefinitions)
	{
		const FWidgetSetupSettings* WidgetSetupSettings = WidgetDefinition->GetWidgetSettingsByTag(Tag);

		if (WidgetSetupSettings == nullptr)
		{
			continue;
		}

		WidgetInstance = ConstructWidgetUsingSettings(*WidgetSetupSettings);

		break;
	}

	checkf(WidgetInstance, TEXT("Widget Setup Settings Does Not Exist For Tag: %s"), *Tag.ToString());

	return WidgetInstance;
}

UUserWidget* UWidgetCreatorComponent::ConstructWidgetUsingSettings(const FWidgetSetupSettings& WidgetSetupSettings)
{
	UWorld* World = GetWorld();

	ULocalPlayer* LocalPlayer = World->GetFirstLocalPlayerFromController();

	APlayerController* PlayerController = LocalPlayer->GetPlayerController(World);

	UUserWidget* WidgetInstance = CreateWidget<UUserWidget>(PlayerController, WidgetSetupSettings.Widget);

	AActor* OwningActor = GetOwner();

	if (WidgetSetupSettings.WidgetCreationType == EWidgetCreationType::AddToViewport)
	{
		WidgetInstance->AddToViewport();
	}

	else
	{
		UWidgetComponentSettings* ComponentSettings = WidgetSetupSettings.WidgetComponentSettings;

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
