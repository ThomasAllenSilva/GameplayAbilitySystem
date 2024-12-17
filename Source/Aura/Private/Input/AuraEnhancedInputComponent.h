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
	void BindInputPressed(const UAuraInputConfigDataAsset* InputDefinition, UserClass* UserObject, Callback FunctionCallback);
};

template<class UserClass, typename Callback>
inline void UAuraEnhancedInputComponent::BindInputPressed(const UAuraInputConfigDataAsset* InputDefinition, UserClass* UserObject, Callback FunctionCallback)
{
	for (TPair<FGameplayTag, UInputAction*>& InputDefinition : InputDefinition->GetInputDefinitions())
	{
		BindAction(InputDefinition.Value, ETriggerEvent::Started, UserObject, FunctionCallback, InputDefinition.Key);
	}
}
