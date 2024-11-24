// Thomas Learning Project


#include "PickupMessagesDataAsset.h"

const FPickupMessageDefinition& UPickupMessagesDataAsset::GetPickupMessageDefinition(const FGameplayTag& Tag)
{
	const FPickupMessageDefinition* MessageDefinition = MessagesDefinitions.Find(Tag);

	checkf(MessageDefinition, TEXT("Could not find a message definition for the tag: %s"), *Tag.GetTagName().ToString());

	return *MessageDefinition;
}
