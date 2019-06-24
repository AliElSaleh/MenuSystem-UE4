// Copyright Ali El Saleh 2019

#include "OptionsMenu.h"
#include "MenuHUD.h"
#include "LogStatics.h"
#include "TimerManager.h"

void UOptionsMenu::NativeConstruct()
{
	Super::NativeConstruct();

	if (!Fade)
		ULogStatics::LogDebugMessage(ERROR, FString("UOptionsMenu::NativeConstruct : Fade anim is null. You forgot to assign the fade animation in widget blueprint"), true);
}

void UOptionsMenu::Forward(const EMenuType Menu)
{
	MenuHUD->HideOptionsMenu();

	Super::Forward(Menu);
}

void UOptionsMenu::GoForward()
{
	switch (MenuSelected)
	{
	case VIDEO:
		MenuHUD->ShowVideoMenu();
		break;

	case AUDIO:
		break;

	case CONTROLS:
		MenuHUD->ShowControlsMenu();
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
