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

	FAuraAttributeInfo AttributeInfo = AttributeInfoData->GetAttributeInfo(AssociatedTag);

	ASSERT_CONDITION(ASC->HasAttributeSetForAttribute(AttributeInfo.AssociatedAttribute), FString::Printf(TEXT("Could Not Find Attribute Set For: %s"), *AttributeInfo.AssociatedAttribute.GetName()))

	FOnGameplayAttributeValueChange& AttributeValueChangeDelegate = ASC->GetGameplayAttributeValueChangeDelegate(AttributeInfo.AssociatedAttribute);

	DelegateHandle = AttributeValueChangeDelegate.AddUObject(this, &UAuraAttributeValueRowUserWidget::InternalOnAttributeValueChanged);

	bool bFound;

	float Value = ASC->GetGameplayAttributeValue(AttributeInfo.AssociatedAttribute, bFound);

	OnAttributeValueChanged(Value);
}

void UAuraAttributeValueRowUserWidget::BeginDestroy()
{
	Super::BeginDestroy();

	UAuraAbilitySystemComponent* ASC = UAuraBlueprintFunctionLibrary::GetLocalPlayerAbilitySystemComponent(this);

	if (ASC == nullptr)
	{
		return;
	}

	const FAuraAttributeInfo& AttributeInfo = AttributeInfoData->GetAttributeInfo(AssociatedTag);

	FOnGameplayAttributeValueChange& AttributeValueChangeDelegate = ASC->GetGameplayAttributeValueChangeDelegate(AttributeInfo.AssociatedAttribute);

	AttributeValueChangeDelegate.Remove(DelegateHandle);
}

void UAuraAttributeValueRowUserWidget::InternalOnAttributeValueChanged(const FOnAttributeChangeData& AttributeData)
{
	OnAttributeValueChanged(AttributeData.NewValue);
}
