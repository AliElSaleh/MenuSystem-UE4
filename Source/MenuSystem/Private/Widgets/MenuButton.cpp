// Copyright Ali El Saleh 2019

#include "MenuButton.h"
#include "MainMenu.h"
#include "Kismet/KismetSystemLibrary.h"
#include "MenuHUD.h"
#include "LogStatics.h"

void UMenuButton::NativeConstruct()
{
	Super::NativeConstruct();

	MainMenuRef = Cast<UMainMenu>(MenuHUD->GetMenu(MAIN_MENU));
}

void UMenuButton::OnButtonReleased()
{
	Super::OnButtonReleased();

	// Error check
	if (IsMainMenuRefNull())
		return;

	MainMenuRef->Forward(ButtonType);
}

void UMenuButton::OnButtonHovered()
{
	// Error check
	if (IsMainMenuRefNull())
		return;

	// Set the menu's tooltip text based on this button's tooltip text set in the widget editor
	MainMenuRef->SetMenuTooltipText(ButtonTooltipText);
}

void UMenuButton::OnButtonUnhovered()
{
	// Error check
	if (IsMainMenuRefNull())
		return;

	// Clear tooltip in main menu
	MainMenuRef->SetMenuTooltipText(FText());
}

bool UMenuButton::IsMainMenuRefNull() const
{
	if (!MainMenuRef)
	{
		ULogStatics::LogDebugMessage(ERROR, FString(GetName() + " | MainMenuRef is null."), true);
		return true;
	}

	return false;
}
