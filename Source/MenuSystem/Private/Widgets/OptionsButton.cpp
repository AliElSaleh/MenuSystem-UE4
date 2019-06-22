// Copyright Ali El Saleh 2019


#include "Widgets/OptionsButton.h"
#include "Widgets/OptionsMenu.h"
#include "MenuHUD.h"
#include "LogStatics.h"

void UOptionsButton::OnButtonReleased()
{
	switch (ButtonType)
	{
	case VIDEO:
		OptionsMenuRef->bVideoSelected = true;
		OptionsMenuRef->bControlsSelected = false;

		if (MenuHUD)
			MenuHUD->HideOptionsMenu();
		else
			ULogStatics::LogDebugMessage(ERROR, FString("HUD is null"), true);
		break;

	case AUDIO:
		break;

	case CONTROLS:
		OptionsMenuRef->bVideoSelected = false;
		OptionsMenuRef->bControlsSelected = true;

		if (MenuHUD)
			MenuHUD->HideOptionsMenu();
		else
			ULogStatics::LogDebugMessage(ERROR, FString("HUD is null"), true);

		break;

	case BACK:
		OptionsMenuRef->bVideoSelected = false;
		OptionsMenuRef->bAudioSelected = false;
		OptionsMenuRef->bControlsSelected = false;

		if (MenuHUD)
			MenuHUD->HideOptionsMenu();
		else
			ULogStatics::LogDebugMessage(ERROR, FString("HUD is null"), true);
		
		break;
	default:
		break;
	}
}

void UOptionsButton::OnButtonHovered()
{
	// Set the menu's tooltip text based on this button's tooltip text set in the widget editor
	OptionsMenuRef->SetOptionsTooltipText(ButtonTooltipText);
}

void UOptionsButton::OnButtonUnhovered()
{
	// Clear tooltip in main menu
	OptionsMenuRef->SetOptionsTooltipText(FText());
}
