// Copyright Ali El Saleh 2019


#include "ButtonBase.h"
#include "MenuHUD.h"
#include "Kismet/GameplayStatics.h"
#include "LogStatics.h"

void UButtonBase::Init()
{
	// Get the Menu HUD
	MenuHUD = Cast<AMenuHUD>(UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetHUD());
}

void UButtonBase::OnButtonReleased()
{
	if (!MenuHUD)
		ULogStatics::LogDebugMessage(ERROR, FString(GetName() + " | OnButtonReleased : MenuHUD is null."), true);
}

void UButtonBase::OnButtonHovered()
{
	ULogStatics::LogDebugMessage(INFO, FString("No implementation for Hovered. Derive from UButtonBase to add functionality."), true);
}

void UButtonBase::OnButtonUnhovered()
{
	ULogStatics::LogDebugMessage(INFO, FString("No implementation for Unhovered. Derive from UButtonBase to add functionality."), true);
}
