// Thomas Learning Project

#pragma once

#include "CoreMinimal.h"

#include "Kismet/BlueprintFunctionLibrary.h"

#include "GameplayTagContainer.h"

#include "Blueprint/UserWidget.h"

#include "UI/HUD/AuraHUD.h"

#include "UI/Interfaces/Initializer/IAuraWidgetControllerInitializer.h"

#include "AuraUIBlueprintFunctionLibrary.generated.h"

USTRUCT()
struct FWidgetDefinition
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UUserWidget> WidgetTemplate;

	UPROPERTY(EditDefaultsOnly)
	FGameplayTag LayerTag;
};

UCLASS()
class AURA_API UAuraUIBlueprintFunctionLibrary final : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "UI")
	static UUserWidget* CreateUserWidgetAtLayer(UObject* OwningObject, TSubclassOf<UUserWidget> UserWidgetClass, const FGameplayTag& LayerTag);

	template <typename WidgetT = UUserWidget, typename OwnerType = UObject>
	static WidgetT* CreateWidgetAtLayer_Internal(OwnerType* OwningObject, TSubclassOf<UUserWidget> UserWidgetClass, const FGameplayTag& LayerTag);
};

template<typename WidgetT, typename OwnerType>
inline WidgetT* UAuraUIBlueprintFunctionLibrary::CreateWidgetAtLayer_Internal(OwnerType* OwningObject, TSubclassOf<UUserWidget> UserWidgetClass, const FGameplayTag& LayerTag)
{
	WidgetT* WidgetInstance = CreateWidget<WidgetT>(OwningObject, UserWidgetClass);

	APlayerController* PlayerController = OwningObject->GetWorld()->GetFirstPlayerController();

	AAuraHUD* AuraHUD = Cast<AAuraHUD>(PlayerController->GetHUD());

	AuraHUD->AddWidgetToLayer(WidgetInstance, LayerTag);

	return WidgetInstance;
}
