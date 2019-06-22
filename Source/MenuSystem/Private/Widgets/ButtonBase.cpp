// Copyright Ali El Saleh 2019


#include "ButtonBase.h"
#include "MenuHUD.h"
#include "Kismet/GameplayStatics.h"
#include "LogStatics.h"

void UButtonBase::NativeConstruct()
{
	Super::NativeConstruct();

	MenuHUD = Cast<AMenuHUD>(UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetHUD());
}

void UButtonBase::OnButtonReleased()
{
	ULogStatics::LogDebugMessage(INFO, FString("No implementation for Released. Derive from UButtonBase to add functionality."), true);
}

void UButtonBase::OnButtonHovered()
{
	ULogStatics::LogDebugMessage(INFO, FString("No implementation for Hovered. Derive from UButtonBase to add functionality."), true);
}

void UButtonBase::OnButtonUnhovered()
{
	ULogStatics::LogDebugMessage(INFO, FString("No implementation for Unhovered. Derive from UButtonBase to add functionality."), true);
}
