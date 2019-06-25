// Copyright Ali El Saleh 2019

#include "MenuBase.h"
#include "MenuHUD.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/GameUserSettings.h"
#include "Engine/Engine.h"
#include "ButtonBase.h"
#include "TimerManager.h"
#include "LogStatics.h"

void UMenuBase::InitializeButtons()
{
	ULogStatics::LogDebugMessage(INFO, FString(GetName() + " | No buttons to initialize!"), true);
}

void UMenuBase::FadeIn()
{
	if (Animation)
		PlayAnimation(Animation, 0.0f, 1, EUMGSequencePlayMode::Reverse);
}

void UMenuBase::FadeOut()
{
	if (Animation)
		PlayAnimation(Animation);
}

void UMenuBase::Init()
{
	MenuHUD = Cast<AMenuHUD>(UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetHUD());
}

void UMenuBase::OnAnimationStarted_Implementation(const UWidgetAnimation* Animation)
{
	SetVisibility(ESlateVisibility::Visible);
}

void UMenuBase::OnAnimationFinished_Implementation(const UWidgetAnimation* Animation)
{
	if (RenderOpacity <= 0.0f)
		SetVisibility(ESlateVisibility::Hidden);
}

void UMenuBase::Apply()
{
	GEngine->GetGameUserSettings()->ApplySettings(false);
}

void UMenuBase::StoreAllSettings(UVerticalBox* ParentWidget)
{
	ULogStatics::LogDebugMessage(INFO, FString(GetName() + " | There are no settings to store!"), true);
}

void UMenuBase::Forward(const EButtonType Menu)
{
	MenuSelected = Menu;
	GetWorld()->GetTimerManager().SetTimer(ForwardTimerHandle, this, &UMenuBase::GoForward, 1.0f, false, Animation->GetEndTime());
}

void UMenuBase::GoForward()
{
	GetWorld()->GetTimerManager().ClearTimer(ForwardTimerHandle);
}

void UMenuBase::Back()
{
	GetWorld()->GetTimerManager().SetTimer(BackTimerHandle, this, &UMenuBase::GoBack, 1.0f, false, Animation->GetEndTime());
}

void UMenuBase::SetMenuTooltipText(const FText& Text)
{
	MenuTooltipText = Text;
}

void UMenuBase::GoBack()
{
	GetWorld()->GetTimerManager().ClearTimer(BackTimerHandle);
}
