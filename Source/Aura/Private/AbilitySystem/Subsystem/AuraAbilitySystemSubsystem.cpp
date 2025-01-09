// Thomas Learning Project


#include "AbilitySystem/Subsystem/AuraAbilitySystemSubsystem.h"

#include "AuraBlueprintFunctionLibrary.h"

const UAuraAbilitySystemComponent* UAuraAbilitySystemSubsystem::GetLocalPlayerAbilitySystemComponent() const
{
	return UAuraBlueprintFunctionLibrary::GetLocalPlayerAbilitySystemComponent(this);
}

void UAuraAbilitySystemSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}
