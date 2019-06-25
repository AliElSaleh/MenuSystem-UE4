// Copyright Ali El Saleh 2019

#include "Widgets/MainMenu.h"
#include "MenuHUD.h"
#include "ButtonBase.h"
#include "WidgetTree.h"
#include "Components/VerticalBox.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/GameplayStatics.h"

void UMainMenu::Init()
{
	Super::Init();

	InitializeButtons();
}

void UMainMenu::InitializeButtons()
{
	Super::InitializeButtons();

	for (auto Button : ParentBox->GetAllChildren())
	{
		Cast<UButtonBase>(Button)->Init();
	}
}

void UMainMenu::SlideOut()
{
	PlayAnimation(Slide);
}

void UMainMenu::Forward(const EButtonType Button)
{
	if (Button == BTN_EXIT)
	{
		UKismetSystemLibrary::QuitGame(GetWorld(), UGameplayStatics::GetPlayerController(GetWorld(), 0), EQuitPreference::Quit, false);
		return;
	}

	if (Button == BTN_CONTINUE)
	{
		MenuHUD->SlideMainMenu();
		return;
	}

	MenuHUD->HideMenu(MAIN_MENU);

	Super::Forward(Button);
}

void UMainMenu::GoForward()
{
	switch (MenuSelected)
	{
	case BTN_NEW_GAME:
		MenuHUD->ShowMenu(NEW_GAME_MENU);
		break;

	case BTN_CONTINUE:
		MenuHUD->SlideMainMenu();
		break;

	case BTN_OPTIONS:
		MenuHUD->ShowMenu(OPTIONS_MENU);
		break;

	case CREDITS:
		break;

	default:
		MenuHUD->ShowMenu(MAIN_MENU);
		break;
	}

	Super::GoForward();
}
