// Copyright Ali El Saleh 2019

#include "OptionsMenu.h"
#include "MenuHUD.h"
#include "LogStatics.h"
#include "TimerManager.h"
#include "ButtonBase.h"
#include "WidgetTree.h"

void UOptionsMenu::Init()
{
	Super::Init();

	ParentBox = Cast<UPanelWidget>(WidgetTree->FindWidget("MenuOptions"));

	InitializeButtons();
}

void UOptionsMenu::InitializeButtons()
{
	for (auto Button : ParentBox->GetAllChildren())
	{
		Cast<UButtonBase>(Button)->Init();
	}
}

void UOptionsMenu::Forward(const EButtonType Menu)
{
	MenuHUD->HideOptionsMenu();

	Super::Forward(Menu);
}

void UOptionsMenu::GoForward()
{
	switch (MenuSelected)
	{
	case BTN_VIDEO:
		MenuHUD->ShowVideoMenu();
		break;

	case BTN_AUDIO:
		MenuHUD->ShowOptionsMenu();
		break;

	case BTN_CONTROLS:
		MenuHUD->ShowControlsMenu();
		break;

	case BTN_BACK:
		MenuHUD->ShowMainMenu();
		break;

	default:
		break;
	}

	Super::GoForward();
}

void UOptionsMenu::Back()
{
	MenuHUD->HideOptionsMenu();

	Super::Back();
}

void UOptionsMenu::GoBack()
{
	MenuHUD->ShowMainMenu();

	Super::GoBack();
}

void UOptionsMenu::SetOptionsTooltipText(const FText& Text)
{
	ButtonTooltipText = Text;
}
