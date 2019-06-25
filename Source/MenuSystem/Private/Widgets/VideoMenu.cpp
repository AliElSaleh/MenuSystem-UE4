// Copyright Ali El Saleh 2019

#include "VideoMenu.h"
#include "LogStatics.h"
#include "GameFramework/GameUserSettings.h"
#include "VideoSetting.h"
#include "Components/VerticalBox.h"
#include "MenuHUD.h"
#include "TimerManager.h"

void UVideoMenu::NativeConstruct()
{
	Super::NativeConstruct();
	
	if (!Animation)
		ULogStatics::LogDebugMessage(ERROR, FString("UVideoMenu::NativeConstruct : Fade anim is null. You forgot to assign the fade animation in widget blueprint"), true);
}

void UVideoMenu::Init()
{
	Super::Init();

	for (auto Setting : VideoSettings)
	{
		Setting->Init();
	}
}

void UVideoMenu::Apply()
{
	for (auto Setting : VideoSettings)
	{
		Setting->Apply();
	}
}

void UVideoMenu::Back()
{
	MenuHUD->HideMenu(VIDEO_MENU);

	Super::Back();
}

void UVideoMenu::GoBack()
{
	MenuHUD->ShowMenu(OPTIONS_MENU);

	Super::GoBack();
}

void UVideoMenu::AddVideoSetting(UVideoSetting* Setting)
{
	VideoSettings.Add(Setting);
}

void UVideoMenu::StoreAllSettings(UVerticalBox* ParentWidget)
{
	for (auto Widget : ParentWidget->GetAllChildren())
	{
		AddVideoSetting(Cast<UVideoSetting>(Widget));
	}
}
