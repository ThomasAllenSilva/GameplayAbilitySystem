// Thomas Learning Project

#pragma once

#include "CoreMinimal.h"

#include "EnhancedInputComponent.h"

#include "Input/AuraInputConfigDataAsset.h"

#include "AuraEnhancedInputComponent.generated.h"

/**
 * 
 */
UCLASS()
class UAuraEnhancedInputComponent : public UEnhancedInputComponent
{
	GENERATED_BODY()
	
public:
	template<class UserClass, typename Callback>
	void BindAbilityInput(const UAuraInputConfigDataAsset* InputDefinition, UserClass* UserObject, Callback FunctionCallback, ETriggerEvent TriggerEvent);
};

template<class UserClass, typename Callback>
inline void UAuraEnhancedInputComponent::BindAbilityInput(const UAuraInputConfigDataAsset* InputDefinition, UserClass* UserObject, Callback FunctionCallback, ETriggerEvent TriggerEvent)
{
	for (const TPair<FGameplayTag, UInputAction*> Definition : InputDefinition->GetInputDefinitions())
	{
		BindAction(Definition.Value, TriggerEvent, UserObject, FunctionCallback, Definition.Key);
	}
}
