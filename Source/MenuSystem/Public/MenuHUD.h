// Copyright Ali El Saleh 2019

#pragma once

#include "GameFramework/HUD.h"
#include "MenuHUD.generated.h"

#define MAIN_MENU 0
#define OPTIONS_MENU 2
#define NEW_GAME_MENU 1
#define CONTROLS_MENU 5
#define VIDEO_MENU 4
#define AUDIO_MENU 5
#define CREDITS_SCREEN 2
#define MASTER_MENU 7

/**
 * A HUD that displays menu options to the user
 */
UCLASS()
class MENUSYSTEM_API AMenuHUD final : public AHUD
{
	GENERATED_BODY()

public:
	AMenuHUD();

	class UUserWidget* GetMenu(int32 Index);

	void ShowMainMenu();
	void HideMainMenu();

	void SlideMainMenu();

	void ShowOptionsMenu();
	void HideOptionsMenu();

	void ShowNewGameMenu();
	void HideNewGameMenu();

	void ShowControlsMenu();
	void HideControlsMenu();

	void ShowVideoMenu();
	void HideVideoMenu();

protected:
	void BeginPlay() override;

	void CreateWidgets();
	void InitializeWidgets();
	void AddWidgetsToScreen();
	void LogWidgetFailures();

	bool AllWidgetsValid();

private:
	TSubclassOf<class UMenuBase> WidgetClass;
	class UMasterMenu* MasterMenu;
};
