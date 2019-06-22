// Copyright Ali El Saleh 2019


#include "Widgets/MainMenu.h"
#include "MenuHUD.h"
#include "Kismet/GameplayStatics.h"

void UMainMenu::SetMenuTooltipText(const FText& Text)
{
	ButtonTooltipText = Text;
}

void UMainMenu::FadeIn()
{
	PlayAnimation(Fade, 0.0f, 1, EUMGSequencePlayMode::Reverse);
}

void UMainMenu::FadeOut()
{
	PlayAnimation(Fade);
}

void UMainMenu::SlideOut()
{
	PlayAnimation(Slide);
}

void UMainMenu::NativeConstruct()
{
	Super::NativeConstruct();

	MenuHUD = Cast<AMenuHUD>(UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetHUD());
}

void UMainMenu::OnAnimationStarted_Implementation(const UWidgetAnimation* Animation)
{
	SetVisibility(ESlateVisibility::Visible);
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
