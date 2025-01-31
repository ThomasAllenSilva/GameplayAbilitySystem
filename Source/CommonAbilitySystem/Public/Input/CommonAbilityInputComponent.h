// Thomas Hero Project

#pragma once

#include "CoreMinimal.h"
#include "EnhancedInputComponent.h"
#include "Data/DataAsset_InputConfig.h"
#include "CommonAbilityInputComponent.generated.h"

/**
 *
 */
UCLASS()
class COMMONABILITYSYSTEM_API UCommonAbilityInputComponent final : public UEnhancedInputComponent
{
	GENERATED_BODY()

public:
	template<class UserObject, typename CallbackFunc>
	void BindNativeInput(const UDataAsset_InputConfig* InputConfig, const FGameplayTag& InputTag, ETriggerEvent TriggerEvent, UserObject* Object, CallbackFunc Func);

	template<class UserClass, typename PressedFuncType, typename ReleasedFuncType>
	void BindAbilityActions(const UDataAsset_InputConfig* InputConfig, UserClass* Object, PressedFuncType PressedFunc, ReleasedFuncType ReleasedFunc);
};

template<class UserObject, typename CallbackFunc>
inline void UCommonAbilityInputComponent::BindNativeInput(const UDataAsset_InputConfig* InputConfig, const FGameplayTag& InputTag, ETriggerEvent TriggerEvent, UserObject* Object, CallbackFunc Func)
{
	check(InputConfig);

	if (UInputAction* InputAction = InputConfig->GetInputActionByTag(InputTag))
	{
		BindAction(InputAction, TriggerEvent, Object, Func);
	}
}

template<class UserClass, typename PressedFuncType, typename ReleasedFuncType>
inline void UCommonAbilityInputComponent::BindAbilityActions(const UDataAsset_InputConfig* InputConfig, UserClass* Object, PressedFuncType PressedFunc, ReleasedFuncType ReleasedFunc)
{
	//TODO: Add Bind Handles
	for (const TPair<FGameplayTag, UInputAction*>& AbilityInputAction : InputConfig->GetAbilityInputActions())
	{
		if (PressedFunc)
		{
			BindAction(AbilityInputAction.Value, ETriggerEvent::Triggered, Object, PressedFunc, AbilityInputAction.Key);
		}

		if (ReleasedFunc) 
		{
			BindAction(AbilityInputAction.Value, ETriggerEvent::Completed, Object, ReleasedFunc, AbilityInputAction.Key);
		}
	}
}
