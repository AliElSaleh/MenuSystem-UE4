// Copyright Ali El Saleh 2019


#include "ControlsMenu.h"
#include "Kismet/GameplayStatics.h"
#include "MenuHUD.h"
#include "OutputDeviceNull.h"
#include "WidgetTree.h"

void UControlsMenu::FadeIn()
{
	PlayAnimation(Fade, 0.0f, 1, EUMGSequencePlayMode::Reverse);
}

void UControlsMenu::FadeOut()
{
	PlayAnimation(Fade);
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

void UControlsMenu::NativeConstruct()
{
	Super::NativeConstruct();

	MenuHUD = Cast<AMenuHUD>(UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetHUD());
}

void UControlsMenu::OnAnimationStarted_Implementation(const UWidgetAnimation* Animation)
{
	SetVisibility(ESlateVisibility::Visible);
}

void UControlsMenu::OnAnimationFinished_Implementation(const UWidgetAnimation* Animation)
{
	if (RenderOpacity <= 0.0f)
	{
		SetVisibility(ESlateVisibility::Hidden);

		MenuHUD->ShowOptionsMenu();
	}
}
