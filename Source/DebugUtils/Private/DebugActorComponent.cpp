// Thomas Learning Project

#include "DebugActorComponent.h"
#include "DebuggableObjectInterface.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystemComponent.h"

UDebugActorComponent::UDebugActorComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

	PrimaryComponentTick.bStartWithTickEnabled = true;

	PrimaryComponentTick.TickInterval = 0.01f;

	bIsEditorOnly = true;
}

void UDebugActorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	if (bActive)
	{
		DisplayDebuggableObjects();
	}
}

void UDebugActorComponent::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);

	UE_LOG(LogTemp, Display, TEXT("Tick function %s"), bActive ? TEXT("Enabled") : TEXT("Disabled"));


	PrimaryComponentTick.SetTickFunctionEnable(bActive);
}

void UDebugActorComponent::DisplayDebuggableObjects()
{
	AActor* Owner = GetOwner();

	check(Owner);

	if (bDisplayComponents)
	{
		for (UActorComponent* Component : Owner->GetComponents())
		{
			if (!Component) continue;

			if (IDebuggableObjectInterface* Debuggable = Cast<IDebuggableObjectInterface>(Component))
			{
				Debuggable->Execute_DisplayDebugInfo(Component);
			}
		}
	}

	if (bDisplayGameplayAbilities)
	{
		UAbilitySystemComponent* ASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(Owner);

		if (ASC == nullptr)
		{
			return;
		}

		TArray<FGameplayAbilitySpec> Abilities = ASC->GetActivatableAbilities();

		for (const FGameplayAbilitySpec& AbilitySpec : Abilities)
		{
			UGameplayAbility* AbilityInstance = AbilitySpec.GetPrimaryInstance();

			if (IDebuggableObjectInterface* Debuggable = Cast<IDebuggableObjectInterface>(AbilityInstance))
			{
				Debuggable->Execute_DisplayDebugInfo(AbilityInstance);
			}
		}
	}
}
