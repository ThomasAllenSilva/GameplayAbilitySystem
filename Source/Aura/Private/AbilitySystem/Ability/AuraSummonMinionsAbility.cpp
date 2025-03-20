// Thomas Learning Project


#include "AbilitySystem/Ability/AuraSummonMinionsAbility.h"
#include "Characters/Enemy/AuraElementalistEnemyCharacter.h"

void UAuraSummonMinionsAbility::OnGiveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec)
{
	Super::OnGiveAbility(ActorInfo, Spec);

	OwnerElementalistEnemyCharacter = CastChecked<AAuraElementalistEnemyCharacter>(OwnerAuraCharacter);
}

TArray<FVector> UAuraSummonMinionsAbility::GetSpawnLocations() const
{
	const FVector ActorLocation = GetAvatarActorFromActorInfo()->GetActorLocation();

	const FVector ActorForward = GetAvatarActorFromActorInfo()->GetActorForwardVector();

	const float IterationAngle = SpreadAngle / MinionsCount;

	TArray<FVector> SpawnPoints;

	FVector SpawnAngle = ActorForward.RotateAngleAxis(-SpreadAngle / 2.0f, FVector::UpVector);

	for (int32 i = 0; i < MinionsCount; i++)
	{
		SpawnAngle = SpawnAngle.RotateAngleAxis(IterationAngle, FVector::UpVector);

		const FVector StartVector = ActorLocation + SpawnAngle * MinSpawnDistance;

		const FVector EndVector = ActorLocation + SpawnAngle * MaxSpawnDistance;

		float RandomSpawnDistance = FMath::RandRange(MinSpawnDistance, MaxSpawnDistance);

		FVector SpawnLocation = ActorLocation + SpawnAngle * RandomSpawnDistance;

		SpawnPoints.Add(SpawnLocation);

		FHitResult OutResult;

		GetWorld()->LineTraceSingleByChannel(OutResult, SpawnLocation + FVector::UpVector * 100, SpawnLocation - FVector::UpVector * 1000, ECollisionChannel::ECC_WorldStatic);

		if (OutResult.bBlockingHit)
		{
			SpawnLocation = OutResult.ImpactPoint;
		}
	}

	return SpawnPoints;
}

APawn* UAuraSummonMinionsAbility::SpawnRandomMinion(const FTransform& SpawnTransform)
{
	const int RandomMinionClassIndex = FMath::RandRange(0, Minions.Num() - 1);

	check(Minions.Num() > 0);

	const TSubclassOf<APawn> MinionClass = Minions[RandomMinionClassIndex];

	check(MinionClass);

	FActorSpawnParameters SpawnParameters;

	SpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

	APawn* Pawn = GetWorld()->SpawnActor<APawn>(MinionClass, SpawnTransform, SpawnParameters);

	Pawn->SpawnDefaultController();

	return Pawn;
}

AAuraElementalistEnemyCharacter* UAuraSummonMinionsAbility::GetElementalistEnemyCharacterFromActorInfo() const
{
	return OwnerElementalistEnemyCharacter.Get();
}
