// Thomas Learning Project


#include "UI/AttributeMenu/AuraAttributeValueRowUserWidget.h"

#include "AbilitySystem/Component/AuraAbilitySystemComponent.h"

#include "AbilitySystem/Data/AttributesInfoDataAsset.h"

#include "Debug.h"

#include "AuraBlueprintFunctionLibrary.h"

void UAuraAttributeValueRowUserWidget::NativeConstruct()
{
	Super::NativeConstruct();

	checkf(AttributeInfoData, TEXT("Cannot Retrieve Attribute Info Using Null Attribute Info Data"));

	UAuraAbilitySystemComponent* ASC = UAuraBlueprintFunctionLibrary::GetLocalPlayerAbilitySystemComponent(this);

	const FAuraAttributeInfo& AttributeInfo = AttributeInfoData->GetAttributeInfo(AssociatedTag);

	//What happens if I try to add Delegate to a attribute that does not exist inside the ASC?
	FOnGameplayAttributeValueChange AttributeValueChangeDelegate = ASC->GetGameplayAttributeValueChangeDelegate(AttributeInfo.AssociatedAttribute);

	AttributeValueChangeDelegate.AddWeakLambda(this,
		[this](const FOnAttributeChangeData& AttributeData)
		{
			OnAttributeValueChanged(AttributeData.NewValue);
		});


	bool bFound;

	float Value = ASC->GetGameplayAttributeValue(AttributeInfo.AssociatedAttribute, bFound);

	VALIDATE_CONDITION(bFound, FString::Printf(TEXT("Could Not Find Attribute Value For: %s"), *AttributeInfo.AssociatedAttribute.GetName()))

	OnAttributeValueChanged(Value);
}
