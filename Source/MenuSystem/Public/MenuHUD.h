// Copyright Ali El Saleh 2019

#pragma once

#include "GameFramework/HUD.h"
#include "MenuHUD.generated.h"

/**
 * A HUD that displays menu options to the user
 */
UCLASS()
class MENUSYSTEM_API AMenuHUD : public AHUD
{
	GENERATED_BODY()

public:
	AMenuHUD();

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
	void AddWidgetsToScreen();
	void LogWidgetFailures();

	bool AllWidgetsValid();

private:
	TArray<TSubclassOf<class UUserWidget>> WidgetClasses;
	TArray<UUserWidget*> Widgets;
	TArray<FName> WidgetNames;
};
