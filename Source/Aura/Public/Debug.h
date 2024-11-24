#pragma once

#define LOG_MESSAGE(StringMessage) LogMessage(StringMessage);

#define LOG_WARNING(StringMessage) LogWarning(StringMessage);

#define LOG_ERROR(StringMessage) LogError(StringMessage);

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
