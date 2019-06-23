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

AMenuHUD::AMenuHUD()
{
	static ConstructorHelpers::FClassFinder<UWidget> MainMenuWidget(TEXT("WidgetBlueprint'/Game/UI/UI_MainMenu.UI_MainMenu_C'"));
	static ConstructorHelpers::FClassFinder<UWidget> OptionsMenuWidget(TEXT("WidgetBlueprint'/Game/UI/UI_OptionsMenu.UI_OptionsMenu_C'"));
	static ConstructorHelpers::FClassFinder<UWidget> NewGameMenuWidget(TEXT("WidgetBlueprint'/Game/UI/UI_NewGameMenu.UI_NewGameMenu_C'"));
	static ConstructorHelpers::FClassFinder<UWidget> ControlsWidget(TEXT("WidgetBlueprint'/Game/UI/UI_ControlsMenu.UI_ControlsMenu_C'"));
	static ConstructorHelpers::FClassFinder<UWidget> VideoMenuWidget(TEXT("WidgetBlueprint'/Game/UI/UI_VideoMenu.UI_VideoMenu_C'"));

	if (MainMenuWidget.Succeeded())
		WidgetClasses.Emplace(MainMenuWidget.Class);

	if (OptionsMenuWidget.Succeeded())
		WidgetClasses.Emplace(OptionsMenuWidget.Class);

	if (NewGameMenuWidget.Succeeded())
		WidgetClasses.Emplace(NewGameMenuWidget.Class);

	if (ControlsWidget.Succeeded())
		WidgetClasses.Emplace(ControlsWidget.Class);

	if (VideoMenuWidget.Succeeded())
		WidgetClasses.Emplace(VideoMenuWidget.Class);

	WidgetNames.Emplace(FName("MainMenuUI"));
	WidgetNames.Emplace(FName("OptionsMenuUI"));
	WidgetNames.Emplace(FName("NewGameMenuUI"));
	WidgetNames.Emplace(FName("ControlsUI"));
	WidgetNames.Emplace(FName("VideoMenuUI"));
}

UUserWidget* AMenuHUD::GetMenu(const int32 Index)
{
	return Widgets[Index];
}

void AMenuHUD::ShowMainMenu()
{
	Cast<UMainMenu>(Widgets[MAIN_MENU])->FadeIn();
}

void AMenuHUD::HideMainMenu()
{
	Cast<UMainMenu>(Widgets[MAIN_MENU])->FadeOut();
}

void AMenuHUD::SlideMainMenu()
{
	Cast<UMainMenu>(Widgets[MAIN_MENU])->SlideOut();
}

void AMenuHUD::ShowOptionsMenu()
{
	Cast<UOptionsMenu>(Widgets[OPTIONS_MENU])->FadeIn();
}

void AMenuHUD::HideOptionsMenu()
{
	Cast<UOptionsMenu>(Widgets[OPTIONS_MENU])->FadeOut();
}

void AMenuHUD::ShowNewGameMenu()
{
	Cast<UNewGameMenu>(Widgets[NEW_GAME_MENU])->FadeIn();
}

void AMenuHUD::HideNewGameMenu()
{
	Cast<UNewGameMenu>(Widgets[NEW_GAME_MENU])->FadeOut();
}

void AMenuHUD::ShowVideoMenu()
{
	Cast<UVideoMenu>(Widgets[VIDEO_MENU])->FadeIn();
}

void AMenuHUD::HideVideoMenu()
{
	Cast<UVideoMenu>(Widgets[VIDEO_MENU])->FadeOut();
}

void AMenuHUD::ShowControlsMenu()
{
	Cast<UControlsMenu>(Widgets[CONTROLS_MENU])->FadeIn();
}

void AMenuHUD::HideControlsMenu()
{
	Cast<UControlsMenu>(Widgets[CONTROLS_MENU])->FadeOut();
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
	Widgets.Reserve(WidgetClasses.Num());

	for (int32 i = 0; i < WidgetClasses.Num(); i++)
		Widgets.Emplace(CreateWidget<UMenuBase>(GetWorld(), WidgetClasses[i], WidgetNames[i]));
}

void AMenuHUD::InitializeWidgets()
{
	Cast<UMainMenu>(Widgets[MAIN_MENU])->Init();
	Cast<UOptionsMenu>(Widgets[OPTIONS_MENU])->Init();
	Cast<UNewGameMenu>(Widgets[NEW_GAME_MENU])->Init();
	Cast<UControlsMenu>(Widgets[CONTROLS_MENU])->Init();
	Cast<UVideoMenu>(Widgets[VIDEO_MENU])->Init();
}

void AMenuHUD::AddWidgetsToScreen()
{
	for (int32 i = 0; i < Widgets.Num(); i++)
	{
		Widgets[i]->AddToViewport();
		Widgets[i]->SetVisibility(ESlateVisibility::Hidden);
	}

	Widgets[0]->SetVisibility(ESlateVisibility::Visible); // Main menu widget
}

void AMenuHUD::LogWidgetFailures()
{
	for (int32 i = 0; i < Widgets.Num(); i++)
	{
		if (!Widgets[i])
			ULogStatics::LogDebugMessage(ERROR, FString("Index ") + FString::FromInt(i) + FString(": Failed to create widget"), true);
	}

	ULogStatics::LogDebugMessage(ERROR, "Could not show widgets because there is at least 1 error", true);
}

bool AMenuHUD::AllWidgetsValid()
{
	for (int32 i = 0; i < Widgets.Num(); i++)
	{
		const bool bIsWidgetValid = Widgets[i];

		if (!bIsWidgetValid)
			return false;
	}

	return true;
}
