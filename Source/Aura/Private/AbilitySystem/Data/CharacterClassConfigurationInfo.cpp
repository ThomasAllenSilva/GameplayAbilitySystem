// Thomas Learning Project


#include "AbilitySystem/Data/CharacterClassConfigurationInfo.h"

const FClassConfigurationInfo& UCharacterClassConfigurationInfo::GetClassConfiguration(const FGameplayTag& ClassTag) const
{
	checkf(ClassesConfigurations.Contains(ClassTag), TEXT("Class Configuration Does Not Exist For Tag: %s"), *ClassTag.ToString());

	return *ClassesConfigurations.Find(ClassTag);
}
