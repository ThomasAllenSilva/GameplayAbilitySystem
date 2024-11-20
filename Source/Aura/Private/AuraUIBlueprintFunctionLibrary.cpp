// Thomas Learning Project


#include "AuraUIBlueprintFunctionLibrary.h"

UUserWidget* UAuraUIBlueprintFunctionLibrary::CreateUserWidgetAtLayer(UObject* OwningObject, TSubclassOf<UUserWidget> UserWidgetClass, const FGameplayTag& LayerTag)
{
	return CreateWidgetAtLayer_Internal<UUserWidget>(OwningObject->GetWorld(), UserWidgetClass, LayerTag);
}
