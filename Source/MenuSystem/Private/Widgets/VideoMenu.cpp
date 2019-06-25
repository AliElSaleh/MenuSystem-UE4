// Copyright Ali El Saleh 2019

#include "VideoMenu.h"
#include "GameFramework/GameUserSettings.h"
#include "VideoSetting.h"
#include "Components/VerticalBox.h"
#include "MenuHUD.h"
#include "TimerManager.h"
#include "WidgetTree.h"

void UVideoMenu::Init()
{
	Super::Init();

	InitializeSettings();

	InitializeButtons();
}

void UVideoMenu::InitializeSettings()
{
	for (auto Setting : VideoSettings)
	{
		Setting->Init();
	}
}

void UVideoMenu::InitializeButtons()
{
	Super::InitializeButtons();

	for (auto Button : ParentBox->GetAllChildren())
	{
		Cast<UButtonBase>(Button)->Init();
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
