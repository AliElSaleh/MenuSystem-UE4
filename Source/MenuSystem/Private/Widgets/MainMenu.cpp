// Copyright Ali El Saleh 2019


#include "Widgets/MainMenu.h"
#include "MenuHUD.h"

void UMainMenu::SetMenuTooltipText(const FText& Text)
{
	ButtonTooltipText = Text;
}

void UMainMenu::SlideOut()
{
	PlayAnimation(Slide);
}

void UMainMenu::Forward(const EMenuType Menu)
{
	MenuHUD->HideMainMenu();

	Super::Forward(Menu);
}

void UMainMenu::GoForward()
{
	switch (MenuSelected)
	{
	case OPTIONS:
		MenuHUD->ShowOptionsMenu();
		break;

	default:
		MenuHUD->ShowMainMenu();
		break;
	}

	Super::GoForward();
}
