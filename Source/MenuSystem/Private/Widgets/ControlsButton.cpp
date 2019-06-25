// Copyright Ali El Saleh 2019


#include "ControlsButton.h"
#include "ControlsMenu.h"
#include "WidgetTree.h"
#include "TextBlock.h"
#include "LogStatics.h"
#include "MenuHUD.h"

void UControlsButton::Init()
{
	Super::Init();

	TextWidget = Cast<UTextBlock>(WidgetTree->FindWidget("Text"));
	ControlsMenuRef = Cast<UControlsMenu>(MenuHUD->GetMenu(CONTROLS_MENU));
}

void UControlsButton::OnButtonReleased()
{
	Super::OnButtonReleased();

	// Error check
	if (IsControlsMenuRefNull())
		return;

	switch (ButtonType)
	{
	case BTN_RESET_INPUT:
		ControlsMenuRef->ResetKeyBindings();
		break;

	case BTN_BACK:
		ControlsMenuRef->Back();
		break;

	default:
		break;
	}
}

void UControlsButton::OnButtonHovered()
{
	HighlightText();

	// Error check
	if (IsControlsMenuRefNull())
		return;

	ControlsMenuRef->SetMenuTooltipText(ButtonTooltipText);
}

void UControlsButton::OnButtonUnhovered()
{
	UnHighlightText();

	// Error check
	if (IsControlsMenuRefNull())
		return;

	ControlsMenuRef->SetMenuTooltipText(FText());
}

bool UControlsButton::IsControlsMenuRefNull() const
{
	if (!ControlsMenuRef)
	{
		ULogStatics::LogDebugMessage(ERROR, FString(GetName() + " | ControlsMenuRef is null."), true);
		return true;
	}

	return false;
}
