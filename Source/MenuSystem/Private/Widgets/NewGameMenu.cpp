// Copyright Ali El Saleh 2019


#include "NewGameMenu.h"
#include "MenuHUD.h"
#include "Kismet/GameplayStatics.h"

void UNewGameMenu::FadeIn()
{
	PlayAnimation(Fade, 0.0f, 1, EUMGSequencePlayMode::Reverse);
}

void UNewGameMenu::FadeOut()
{
	PlayAnimation(Fade);
}

void UNewGameMenu::NativeConstruct()
{
	Super::NativeConstruct();

	MenuHUD = Cast<AMenuHUD>(UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetHUD());
}

void UNewGameMenu::OnAnimationStarted_Implementation(const UWidgetAnimation* Animation)
{
	SetVisibility(ESlateVisibility::Visible);
}

void UNewGameMenu::OnAnimationFinished_Implementation(const UWidgetAnimation* Animation)
{
	if (RenderOpacity <= 0.0f)
		SetVisibility(ESlateVisibility::Hidden);
}
