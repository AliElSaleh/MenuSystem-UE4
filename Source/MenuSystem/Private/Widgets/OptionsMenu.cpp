// Copyright Ali El Saleh 2019


#include "OptionsMenu.h"
#include "MenuHUD.h"
#include "Kismet/GameplayStatics.h"

void UOptionsMenu::SetOptionsTooltipText(const FText& Text)
{
	ButtonTooltipText = Text;
}

void UOptionsMenu::FadeIn()
{
	PlayAnimation(Fade, 0.0f, 1, EUMGSequencePlayMode::Reverse);
}

void UOptionsMenu::FadeOut()
{
	PlayAnimation(Fade);
}

void UOptionsMenu::NativeConstruct()
{
	Super::NativeConstruct();

	MenuHUD = Cast<AMenuHUD>(UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetHUD());
}

void UOptionsMenu::OnAnimationStarted_Implementation(const UWidgetAnimation* Animation)
{
	SetVisibility(ESlateVisibility::Visible);
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
