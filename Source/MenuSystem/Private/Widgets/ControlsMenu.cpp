// Copyright Ali El Saleh 2019


#include "ControlsMenu.h"
#include "MenuHUD.h"
#include "OutputDeviceNull.h"
#include "LogStatics.h"

void UControlsMenu::NativeConstruct()
{
	Super::NativeConstruct();

	if (!Fade)
		ULogStatics::LogDebugMessage(ERROR, FString("UControlsMenu::NativeConstruct : Fade anim is null. You forgot to assign the fade animation in widget blueprint"), true);
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

void UControlsMenu::OnAnimationFinished_Implementation(const UWidgetAnimation* Animation)
{
	if (RenderOpacity <= 0.0f)
	{
		SetVisibility(ESlateVisibility::Hidden);

		MenuHUD->ShowOptionsMenu();
	}
}
