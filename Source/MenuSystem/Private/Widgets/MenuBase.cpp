// Copyright Ali El Saleh 2019

#include "MenuBase.h"
#include "MenuHUD.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/GameUserSettings.h"
#include "Engine/Engine.h"
#include "LogStatics.h"

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

TArray<UMenuSetting*> UMenuBase::GetAllSettings()
{
	return TArray<UMenuSetting*>();
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
