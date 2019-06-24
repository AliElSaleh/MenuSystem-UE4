// Copyright Ali El Saleh 2019

#include "MenuHUD.h"
#include "ConstructorHelpers.h"
#include "Widget.h"
#include "UserWidget.h"
#include "MainMenu.h"
#include "NewGameMenu.h"
#include "OptionsMenu.h"
#include "VideoMenu.h"
#include "ControlsMenu.h"
#include "LogStatics.h"
#include "MasterMenu.h"

AMenuHUD::AMenuHUD()
{
	static ConstructorHelpers::FClassFinder<UWidget> MasterMenu(TEXT("WidgetBlueprint'/Game/UI/UI_MasterMenu.UI_MasterMenu_C'"));

	if (MasterMenu.Succeeded())
		WidgetClass = MasterMenu.Class;
}

UUserWidget* AMenuHUD::GetMenu(const int32 Index)
{
	return Cast<UMasterMenu>(MasterMenu)->GetMenus()[Index];
}

void AMenuHUD::ShowMainMenu()
{
	Cast<UMainMenu>(MasterMenu->GetMenu(MAIN_MENU))->FadeIn();
	MasterMenu->SwitchToMenuIndex(MAIN_MENU);
}

void AMenuHUD::HideMainMenu()
{
	Cast<UMainMenu>(MasterMenu->GetMenu(MAIN_MENU))->FadeOut();
}

void AMenuHUD::SlideMainMenu()
{
	Cast<UMainMenu>(MasterMenu->GetMenu(MAIN_MENU))->SlideOut();
}

void AMenuHUD::ShowOptionsMenu()
{
	Cast<UOptionsMenu>(MasterMenu->GetMenu(OPTIONS_MENU))->FadeIn();
	MasterMenu->SwitchToMenuIndex(OPTIONS_MENU);
}

void AMenuHUD::HideOptionsMenu()
{
	Cast<UOptionsMenu>(MasterMenu->GetMenu(OPTIONS_MENU))->FadeOut();
}

void AMenuHUD::ShowNewGameMenu()
{
	//Cast<UNewGameMenu>(Widgets[NEW_GAME_MENU])->FadeIn();
}

void AMenuHUD::HideNewGameMenu()
{
	//Cast<UNewGameMenu>(Widgets[NEW_GAME_MENU])->FadeOut();
}

void AMenuHUD::ShowVideoMenu()
{
	//Cast<UVideoMenu>(Widgets[VIDEO_MENU])->FadeIn();
}

void AMenuHUD::HideVideoMenu()
{
	//Cast<UVideoMenu>(Widgets[VIDEO_MENU])->FadeOut();
}

void AMenuHUD::ShowControlsMenu()
{
	//Cast<UControlsMenu>(Widgets[CONTROLS_MENU])->FadeIn();
}

void AMenuHUD::HideControlsMenu()
{
	//Cast<UControlsMenu>(Widgets[CONTROLS_MENU])->FadeOut();
}

void AMenuHUD::BeginPlay()
{
	CreateWidgets();

	// Error check for newley created widgets
	if (AllWidgetsValid())
	{
		AddWidgetsToScreen();
		InitializeWidgets();
	}
	else
		LogWidgetFailures();
}

void AMenuHUD::CreateWidgets()
{
	MasterMenu = CreateWidget<UMasterMenu>(GetWorld(), WidgetClass, FName("MasterMenuUI"));
}

void AMenuHUD::InitializeWidgets()
{
	MasterMenu->Init();
}

void AMenuHUD::AddWidgetsToScreen()
{
	MasterMenu->AddToViewport();
	MasterMenu->SetVisibility(ESlateVisibility::Visible); // Master menu widget
}

void AMenuHUD::LogWidgetFailures()
{
	if (!MasterMenu)
		ULogStatics::LogDebugMessage(ERROR, FString("Failed to create master menu widget"), true);
}

bool AMenuHUD::AllWidgetsValid()
{
	if (!MasterMenu)
		return false;

	return true;
}
