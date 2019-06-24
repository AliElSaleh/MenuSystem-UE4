// Copyright Ali El Saleh 2019


#include "Widgets/OptionsButton.h"
#include "Widgets/OptionsMenu.h"
#include "MenuHUD.h"
#include "LogStatics.h"

void UOptionsButton::NativeConstruct()
{
	Super::NativeConstruct();

	OptionsMenuRef = Cast<UOptionsMenu>(MenuHUD->GetMenu(OPTIONS_MENU));
}

void UOptionsButton::OnButtonReleased()
{
	Super::OnButtonReleased(); 

	// Error check
	if (IsOptionsMenuRefNull())
		return;

	OptionsMenuRef->Forward(ButtonType);
}

void UOptionsButton::OnButtonHovered()
{
	// Error check
	if (IsOptionsMenuRefNull())
		return;

	// Set the menu's tooltip text based on this button's tooltip text set in the widget editor
	OptionsMenuRef->SetOptionsTooltipText(ButtonTooltipText);
}

void UOptionsButton::OnButtonUnhovered()
{
	// Error check
	if (IsOptionsMenuRefNull())
		return;

	// Clear tooltip in main menu
	OptionsMenuRef->SetOptionsTooltipText(FText());
}

bool UOptionsButton::IsOptionsMenuRefNull() const
{
	if (!OptionsMenuRef)
	{
		ULogStatics::LogDebugMessage(ERROR, FString(GetName() + " | OptionsMenuRef is null."), true);
		return true;
	}

	return false;
}
