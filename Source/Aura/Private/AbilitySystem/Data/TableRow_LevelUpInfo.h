// Thomas Learning Project

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "TableRow_LevelUpInfo.generated.h"

USTRUCT()
struct FLevelUpInfoTableRow final : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	int XPRequirement;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	int AttributePointAward;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	int AbilityPointAward;
};
