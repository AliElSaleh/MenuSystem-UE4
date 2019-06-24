// Copyright Ali El Saleh 2019

#include "MenuBase.h"
#include "MenuHUD.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/GameUserSettings.h"
#include "Engine/Engine.h"
#include "LogStatics.h"
#include "TimerManager.h"

void UMenuBase::NativeConstruct()
{
	Super::NativeConstruct();

	MenuHUD = Cast<AMenuHUD>(UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetHUD());
}

void UMenuBase::FadeIn()
{
	if (Fade)
		PlayAnimation(Fade, 0.0f, 1, EUMGSequencePlayMode::Reverse);
}

void UMenuBase::FadeOut()
{
	if (Fade)
		PlayAnimation(Fade);
}

void UMenuBase::Init()
{
	
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

}

void UMenuBase::Forward(const EMenuType Menu)
{
	MenuSelected = Menu;
	GetWorld()->GetTimerManager().SetTimer(ForwardTimerHandle, this, &UMenuBase::GoForward, 1.0f, false, Fade->GetEndTime());
}

void UMenuBase::GoForward()
{
	GetWorld()->GetTimerManager().ClearTimer(ForwardTimerHandle);
}

void UMenuBase::Back()
{
	GetWorld()->GetTimerManager().SetTimer(BackTimerHandle, this, &UMenuBase::GoBack, 1.0f, false, Fade->GetEndTime());
}

void UMenuBase::GoBack()
{
	GetWorld()->GetTimerManager().ClearTimer(BackTimerHandle);
}
