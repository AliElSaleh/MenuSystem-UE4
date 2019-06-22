// Copyright Ali El Saleh 2019

#include "VideoMenu.h"
#include "MenuHUD.h"
#include "Kismet/GameplayStatics.h"
#include "LogStatics.h"

void UVideoMenu::NativeConstruct()
{
	Super::NativeConstruct();

	MenuHUD = Cast<AMenuHUD>(UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetHUD());
}

void UVideoMenu::FadeIn()
{
	if (Fade)
		PlayAnimation(Fade, 0.0f, 1, EUMGSequencePlayMode::Reverse);
	else
		ULogStatics::LogDebugMessage(ERROR, FString("Fade anim is null. You forgot to assign the fade animation in video menu widget blueprint"), true);
}

void UVideoMenu::FadeOut()
{
	if (Fade)
		PlayAnimation(Fade);
	else
		ULogStatics::LogDebugMessage(ERROR, FString("Fade anim is null. You forgot to assign the fade animation in video menu widget blueprint"), true);
}

void UVideoMenu::OnAnimationStarted_Implementation(const UWidgetAnimation* Animation)
{
	SetVisibility(ESlateVisibility::Visible);
}

void UVideoMenu::OnAnimationFinished_Implementation(const UWidgetAnimation* Animation)
{
	if (RenderOpacity <= 0.0f)
		SetVisibility(ESlateVisibility::Hidden);
}
