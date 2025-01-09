// Thomas Learning Project


#include "Input/AuraInputConfigDataAsset.h"

UInputAction* UAuraInputConfigDataAsset::GetInputAction(const FGameplayTag& Tag)
{
	return InputDefinitions[Tag];
}
