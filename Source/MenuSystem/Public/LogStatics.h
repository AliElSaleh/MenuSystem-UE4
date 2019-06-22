// Copyright Ali El Saleh 2019

#pragma once

#include "Kismet/GameplayStatics.h"
#include "LogStatics.generated.h"

UENUM()
enum ELogLevel
{
	INFO,
	SUCCESS,
	WARNING,
	ERROR
};

/**
 * A list of log utility functions
 */
UCLASS()
class MENUSYSTEM_API ULogStatics : public UGameplayStatics
{
	GENERATED_BODY()

public:
	// Log whether the object is valid or not
	static void LogObjectValidity(UObject* ObjectRef, bool bLogInViewport = false);

	// Log a debug message to the console or viewport
	static void LogDebugMessage(ELogLevel LogLevel, const FString& LogMessage, bool bLogInViewport = false);
};
