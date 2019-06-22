// Copyright Ali El Saleh 2019

#include "Widgets/MenuButton.h"
#include "Widgets/MainMenu.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "MenuHUD.h"
#include "LogStatics.h"

void UMenuButton::NativeConstruct()
{
	Super::NativeConstruct();

	MenuHUD = Cast<AMenuHUD>(UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetHUD());
}

void UMenuButton::OnButtonReleased()
{
	switch (ButtonType)
	{
	case NEW_GAME:
		MainMenuRef->bNewGameSelected = true;

		if (MenuHUD)
			MenuHUD->HideMainMenu();
		else
			ULogStatics::LogDebugMessage(ERROR, FString("HUD is null"), true);

		break;
	case CONTINUE:
		if (MenuHUD)
			MenuHUD->SlideMainMenu();
		else
			ULogStatics::LogDebugMessage(ERROR, FString("HUD is null"), true);

		break;
	case OPTIONS:
		MainMenuRef->bOptionsSelected = true;

		if (MenuHUD)
			MenuHUD->HideMainMenu();
		else
			ULogStatics::LogDebugMessage(ERROR, FString("HUD is null"), true);

		break;
	case CREDITS:
		if (MenuHUD)
			MenuHUD->HideMainMenu();
		else
			ULogStatics::LogDebugMessage(ERROR, FString("HUD is null"), true);
		break;

	case EXIT:
		UKismetSystemLibrary::QuitGame(GetWorld(), UGameplayStatics::GetPlayerController(GetWorld(), 0), EQuitPreference::Quit, true);
		break;

	default:
		ULogStatics::LogDebugMessage(WARNING, FString("Button doesn't exist"), true);
		break;
	}
}

void UMenuButton::OnButtonHovered()
{
	// Set the menu's tooltip text based on this button's tooltip text set in the widget editor
	MainMenuRef->SetMenuTooltipText(ButtonTooltipText);
}

void UMenuButton::OnButtonUnhovered()
{
	// Clear tooltip in main menu
	MainMenuRef->SetMenuTooltipText(FText());
}
