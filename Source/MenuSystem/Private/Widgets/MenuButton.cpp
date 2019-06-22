// Copyright Ali El Saleh 2019

#include "MenuButton.h"
#include "MainMenu.h"
#include "Kismet/KismetSystemLibrary.h"
#include "MenuHUD.h"
#include "LogStatics.h"

void UMenuButton::OnButtonReleased()
{
	Super::OnButtonReleased();

	// Error check
	if (IsMainMenuRefNull())
		return;

	switch (ButtonType)
	{
	case NEW_GAME:
		MainMenuRef->bNewGameSelected = true;
		MainMenuRef->bOptionsSelected = false;

		MenuHUD->HideMainMenu();
		break;

	case CONTINUE:
		MainMenuRef->bNewGameSelected = false;
		MainMenuRef->bOptionsSelected = false;

		MenuHUD->SlideMainMenu();
		break;

	case OPTIONS:
		MainMenuRef->bNewGameSelected = false;
		MainMenuRef->bOptionsSelected = true;

		MenuHUD->HideMainMenu();
		break;

	case CREDITS:
		MainMenuRef->bNewGameSelected = false;
		MainMenuRef->bOptionsSelected = false;

		MenuHUD->HideMainMenu();
		break;

	case EXIT:
		UKismetSystemLibrary::QuitGame(GetWorld(), UGameplayStatics::GetPlayerController(GetWorld(), 0), EQuitPreference::Quit, true);
		break;

	default:
		ULogStatics::LogDebugMessage(INFO, FString("UMenuButton::OnButtonReleased : Button does not exist!"), true);
		break;
	}
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
