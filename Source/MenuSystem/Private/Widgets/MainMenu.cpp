// Copyright Ali El Saleh 2019

#include "Widgets/MainMenu.h"
#include "MenuHUD.h"
#include "ButtonBase.h"
#include "WidgetTree.h"
#include "Components/VerticalBox.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/GameplayStatics.h"

void UMainMenu::Init()
{
	Super::Init();

	ParentBox = Cast<UPanelWidget>(WidgetTree->FindWidget("MenuOptions"));

	InitializeButtons();
}

void UMainMenu::InitializeButtons()
{
	for (auto Button : ParentBox->GetAllChildren())
	{
		Cast<UButtonBase>(Button)->Init();
	}
}

void UMainMenu::SetMenuTooltipText(const FText& Text)
{
	ButtonTooltipText = Text;
}

void UMainMenu::SlideOut()
{
	PlayAnimation(Slide);
}

void UMainMenu::Forward(const EButtonType Button)
{
	if (Button == BTN_EXIT)
	{
		UKismetSystemLibrary::QuitGame(GetWorld(), UGameplayStatics::GetPlayerController(GetWorld(), 0), EQuitPreference::Quit, false);
		return;
	}

	MenuHUD->HideMainMenu();

	Super::Forward(Button);
}

void UMainMenu::GoForward()
{
	switch (MenuSelected)
	{
	case BTN_NEW_GAME:
		MenuHUD->ShowNewGameMenu();
		break;

	case BTN_CONTINUE:
		MenuHUD->SlideMainMenu();
		break;

	case BTN_OPTIONS:
		MenuHUD->ShowOptionsMenu();
		break;

	case CREDITS:
		break;

	default:
		MenuHUD->ShowMainMenu();
		break;
	}

	Super::GoForward();
}
