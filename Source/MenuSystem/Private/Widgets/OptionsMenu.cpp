// Copyright Ali El Saleh 2019

#include "OptionsMenu.h"
#include "MenuHUD.h"
#include "LogStatics.h"

void UOptionsMenu::NativeConstruct()
{
	Super::NativeConstruct();

	if (!Fade)
		ULogStatics::LogDebugMessage(ERROR, FString("UOptionsMenu::NativeConstruct : Fade anim is null. You forgot to assign the fade animation in widget blueprint"), true);
}

void UOptionsMenu::OnAnimationFinished_Implementation(const UWidgetAnimation* Animation)
{
	if (RenderOpacity <= 0.0f)
	{
		SetVisibility(ESlateVisibility::Hidden);
		
		if (bControlsSelected)
			MenuHUD->ShowControlsMenu();
		else if (bVideoSelected)
			MenuHUD->ShowVideoMenu();
		else
			MenuHUD->ShowMainMenu();
	}

	bControlsSelected = false;
}

void UOptionsMenu::SetOptionsTooltipText(const FText& Text)
{
	ButtonTooltipText = Text;
}
