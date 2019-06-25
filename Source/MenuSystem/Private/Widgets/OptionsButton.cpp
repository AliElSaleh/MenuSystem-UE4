// Copyright Ali El Saleh 2019


#include "Widgets/OptionsButton.h"
#include "Widgets/OptionsMenu.h"
#include "MenuHUD.h"
#include "LogStatics.h"
#include "WidgetTree.h"
#include "TextBlock.h"

void UOptionsButton::Init()
{
	Super::Init();

	TextWidget = Cast<UTextBlock>(WidgetTree->FindWidget("Text"));
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
	HighlightText();

	// Error check
	if (IsOptionsMenuRefNull())
		return;

	// Set the menu's tooltip text based on this button's tooltip text set in the widget editor
	OptionsMenuRef->SetMenuTooltipText(ButtonTooltipText);
}

void UOptionsButton::OnButtonUnhovered()
{
	UnHighlightText();

	// Error check
	if (IsOptionsMenuRefNull())
		return;

	// Clear tooltip in main menu
	OptionsMenuRef->SetMenuTooltipText(FText());
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
