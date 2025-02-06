// Thomas Learning Project

#pragma once

#include "Tickable.h"
#include "TickableObject.generated.h"

DECLARE_DELEGATE_OneParam(FOnTickSignature, float);

UCLASS()
class COMMONFRAMEWORK_API UTickableObject final : public UObject, public FTickableGameObject
{
	GENERATED_BODY()

public:
	FOnTickSignature OnTick;

protected:
	virtual void Tick(float DeltaTime) override;

	virtual TStatId GetStatId() const override;
};
