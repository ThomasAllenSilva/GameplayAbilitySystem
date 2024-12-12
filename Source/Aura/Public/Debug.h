#pragma once

#if !UE_BUILD_SHIPPING
#define LOG_MESSAGE(StringMessage) LogMessage(StringMessage);

#define LOG_WARNING(StringMessage) LogWarning(StringMessage);

#define LOG_ERROR(StringMessage) LogError(StringMessage);

#define VALIDATE_CONDITION(Condition, StringMessage) LogIfInvalidCondition(Condition, StringMessage);

#define ASSERT_CONDITION(Condition, StringMessage) LogIfInvalidCondition(Condition, StringMessage);
#else

#define LOG_MESSAGE(StringMessage)

#define LOG_WARNING(StringMessage)

#define LOG_ERROR(StringMessage)

#define VALIDATE_CONDITION(Condition, StringMessage)

#define ASSERT_CONDITION(Condition, StringMessage)
#endif

static void LogMessage(const FString& Message)
{
	if (GEngine != nullptr)
	{
		GEngine->AddOnScreenDebugMessage(-1, 1.5f, FColor::White, Message);
	}

	UE_LOG(LogTemp, Display, TEXT("%s"), *Message);
}

static void LogWarning(const FString& Message)
{
	if (GEngine != nullptr)
	{
		GEngine->AddOnScreenDebugMessage(-1, 1.5f, FColor::Yellow, Message);
	}

	UE_LOG(LogTemp, Warning, TEXT("%s"), *Message);
}

static void LogError(const FString& Message)
{
	if (GEngine != nullptr)
	{
		GEngine->AddOnScreenDebugMessage(-1, 1.5f, FColor::Red, Message);
	}

	UE_LOG(LogTemp, Error, TEXT("%s"), *Message);
}

static void LogIfInvalidCondition(bool bCondition, const FString& Message)
{
	if (bCondition == false)
	{
		LogMessage(Message);
	}
}

static void CrashIfInvalidCondition(bool bCondition, const FString& Message)
{
	checkf(bCondition, TEXT("%s"), *Message)
}