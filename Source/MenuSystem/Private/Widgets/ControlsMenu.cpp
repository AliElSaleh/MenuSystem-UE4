// Copyright Ali El Saleh 2019


#include "ControlsMenu.h"
#include "MenuHUD.h"
#include "WidgetTree.h"
#include "Components/VerticalBox.h"
#include "OutputDeviceNull.h"
#include "LogStatics.h"
#include "ButtonBase.h"

void UControlsMenu::NativeConstruct()
{
	Super::NativeConstruct();

	if (!Fade)
		ULogStatics::LogDebugMessage(ERROR, FString("UControlsMenu::NativeConstruct : Fade anim is null. You forgot to assign the fade animation in widget blueprint"), true);
}

void UControlsMenu::Init()
{
	Super::Init();

	ParentBox = Cast<UPanelWidget>(WidgetTree->FindWidget("MenuOptions"));

	InitializeButtons();
}

void UControlsMenu::InitializeButtons()
{
	for (auto Button : ParentBox->GetAllChildren())
	{
		Cast<UButtonBase>(Button)->Init();
	}
}

void UControlsMenu::Back()
{
	MenuHUD->HideControlsMenu();

	Super::Back();
}

void UControlsMenu::GoBack()
{
	MenuHUD->ShowOptionsMenu();

	Super::GoBack();
}

void UControlsMenu::ResetKeyBindings()
{
	for (auto Slot : ControlsSlots)
	{
		// Call function in BP to reset key mapping to default
		FOutputDeviceNull OutputDevice;
		Slot->CallFunctionByNameWithArguments(TEXT("ResetKeyMappings"), OutputDevice, nullptr, true);
	}
}
