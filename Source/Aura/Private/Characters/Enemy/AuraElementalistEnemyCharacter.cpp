// Thomas Learning Project

#include "Characters/Enemy/AuraElementalistEnemyCharacter.h"

void AAuraElementalistEnemyCharacter::IncrementMinionsCount(int Amount)
{
	check(Amount > 0);

	CurrentMinionsCount += Amount;
}

void AAuraElementalistEnemyCharacter::DecrementMinionsCount(int Amount)
{
	check(Amount < 0);

	CurrentMinionsCount += Amount;
}

int AAuraElementalistEnemyCharacter::GetCurrentMinionsCount() const
{
	return CurrentMinionsCount;
}

int AAuraElementalistEnemyCharacter::GetTargetMinionsCount() const
{
	return TargetMinionsCount;
}

bool AAuraElementalistEnemyCharacter::ShouldSpawnNewMinions() const
{
	return CurrentMinionsCount < MinMinionsCount;
}

bool AAuraElementalistEnemyCharacter::CanSpawnNewMinion() const
{
	return CurrentMinionsCount < TargetMinionsCount;
}
