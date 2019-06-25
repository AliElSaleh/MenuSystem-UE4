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
	return MasterMenu->GetMenus()[Index];
}

void AMenuHUD::ShowMainMenu()
{
	MasterMenu->GetMenu(MAIN_MENU)->FadeIn();
	MasterMenu->SwitchToMenuIndex(MAIN_MENU);
}

void AMenuHUD::HideMainMenu()
{
	MasterMenu->GetMenu(MAIN_MENU)->FadeOut();
}

void AMenuHUD::SlideMainMenu()
{
	Cast<UMainMenu>(MasterMenu->GetMenu(MAIN_MENU))->SlideOut();
}

void AMenuHUD::ShowOptionsMenu()
{
	MasterMenu->GetMenu(OPTIONS_MENU)->FadeIn();
	MasterMenu->SwitchToMenuIndex(OPTIONS_MENU);
}

void AMenuHUD::HideOptionsMenu()
{
	MasterMenu->GetMenu(OPTIONS_MENU)->FadeOut();
}

void AMenuHUD::ShowNewGameMenu()
{
	MasterMenu->GetMenu(NEW_GAME_MENU)->FadeIn();
	MasterMenu->SwitchToMenuIndex(NEW_GAME_MENU);
}

void AMenuHUD::HideNewGameMenu()
{
	MasterMenu->GetMenu(NEW_GAME_MENU)->FadeOut();
}

void AMenuHUD::ShowVideoMenu()
{
	MasterMenu->GetMenu(VIDEO_MENU)->FadeIn();
	MasterMenu->SwitchToMenuIndex(VIDEO_MENU);
}

void AMenuHUD::HideVideoMenu()
{
	MasterMenu->GetMenu(VIDEO_MENU)->FadeOut();
}

void AMenuHUD::ShowControlsMenu()
{
	MasterMenu->GetMenu(CONTROLS_MENU)->FadeIn();
	MasterMenu->SwitchToMenuIndex(CONTROLS_MENU);
}

void AMenuHUD::HideControlsMenu()
{
	MasterMenu->GetMenu(CONTROLS_MENU)->FadeOut();
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
	return MasterMenu != nullptr;
}
