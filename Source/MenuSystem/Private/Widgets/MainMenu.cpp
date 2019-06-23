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

void UMainMenu::OnAnimationFinished_Implementation(const UWidgetAnimation* Animation)
{
	if (RenderOpacity <= 0.0f)
	{
		SetVisibility(ESlateVisibility::Hidden);

		if (bOptionsSelected)
			MenuHUD->ShowOptionsMenu();
		else if (bNewGameSelected)
			MenuHUD->ShowNewGameMenu();
	}

	bNewGameSelected = false;
	bOptionsSelected = false;
}
