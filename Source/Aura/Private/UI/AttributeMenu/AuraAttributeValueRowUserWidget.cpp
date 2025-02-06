// Thomas Learning Project

#include "UI/AttributeMenu/AuraAttributeValueRowUserWidget.h"
#include "Components/CommonAbilitySystemComponent.h"
#include "AbilitySystem/Data/AttributesInfoDataAsset.h"
#include "CommonAbilityFunctionLibrary.h"
#include "Debug.h"

void UAuraAttributeValueRowUserWidget::NativeConstruct()
{
	Super::NativeConstruct();

	checkf(AttributeInfoData, TEXT("Cannot Retrieve Attribute Info Using Null Attribute Info Data"));

	UCommonAbilitySystemComponent* ASC = UCommonAbilityFunctionLibrary::GetLocalPlayerAbilitySystemComponent(this);

	if (ASC->GetIsInitialized() == true)
	{
		InitializeAttributeRow();
	}

	else
	{
		ASC->OnInitialized.AddWeakLambda(this, [this]()
		{
			InitializeAttributeRow();
		});
	}
}

void UAuraAttributeValueRowUserWidget::BeginDestroy()
{
	Super::BeginDestroy();

	UCommonAbilitySystemComponent* ASC = UCommonAbilityFunctionLibrary::GetLocalPlayerAbilitySystemComponent(this);

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

void UAuraAttributeValueRowUserWidget::InitializeAttributeRow()
{
	UCommonAbilitySystemComponent* ASC = UCommonAbilityFunctionLibrary::GetLocalPlayerAbilitySystemComponent(this);

	FAuraAttributeInfo AttributeInfo = AttributeInfoData->GetAttributeInfo(AssociatedTag);

	ASSERT_CONDITION(AttributeInfo.AssociatedAttribute.IsValid(), FString::Printf(TEXT("Attribute Set Is Not Valid. Tag: %s"), *AssociatedTag.ToString()));
	ASSERT_CONDITION(ASC->HasAttributeSetForAttribute(AttributeInfo.AssociatedAttribute), FString::Printf(TEXT("Could Not Find Attribute Set For: %s"), *AttributeInfo.AssociatedAttribute.GetName()));

	FOnGameplayAttributeValueChange& AttributeValueChangeDelegate = ASC->GetGameplayAttributeValueChangeDelegate(AttributeInfo.AssociatedAttribute);

	DelegateHandle = AttributeValueChangeDelegate.AddUObject(this, &UAuraAttributeValueRowUserWidget::InternalOnAttributeValueChanged);

	bool bFound;

	float Value = ASC->GetGameplayAttributeValue(AttributeInfo.AssociatedAttribute, bFound);

	OnAttributeValueChanged(Value);
}
