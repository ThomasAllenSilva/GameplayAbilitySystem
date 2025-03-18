// Thomas Learning Project


#include "AbilitySystem/Ability/AuraSummonMinionsAbility.h"

TArray<FVector> UAuraSummonMinionsAbility::GetSpawnLocations() const
{
	const FVector ActorLocation = GetAvatarActorFromActorInfo()->GetActorLocation();

	const FVector ActorForward = GetAvatarActorFromActorInfo()->GetActorForwardVector();

	const float IterationAngle = SpreadAngle / MinionsCount;

	TArray<FVector> SpawnPoints;

	const FVector InitialAngle = ActorForward.RotateAngleAxis(-SpreadAngle / 2, FVector::UpVector);

	for (int32 i = 0; i < MinionsCount; i++)
	{
		//holy shit, I'm pretty tired. Please my self from the future, finish this.. please
		FVector SpawnPoint = InitialAngle.RotateAngleAxis(IterationAngle * 0, FVector::UpVector);
	}




	return SpawnPoints;
}
