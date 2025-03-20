// Thomas Learning Project

#include "Characters/Enemy/AuraElementalistEnemyCharacter.h"

void AAuraElementalistEnemyCharacter::IncrementMinionsCount(int Amount)
{
	check(Amount > 0);

	MinionsCount += Amount;
}

void AAuraElementalistEnemyCharacter::DecrementMinionsCount(int Amount)
{
	check(Amount < 0);

	MinionsCount += Amount;
}

int AAuraElementalistEnemyCharacter::GetCurrentMinionsCount() const
{
	return MinionsCount;
}
