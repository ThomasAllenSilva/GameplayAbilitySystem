// Thomas Learning Project

#include "UI/Base/ContextualUserWidget.h"

void UContextualUserWidget::SetOwningActor(AActor* InOwningActor)
{
	OwningActor = InOwningActor;

	Internal_OwningActorSet();
}

void UContextualUserWidget::Internal_OwningActorSet()
{
	OwningActorSet(OwningActor);
}
