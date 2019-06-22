// Copyright Ali El Saleh 2019


#include "ControlsButton.h"
#include "ControlsMenu.h"
#include "WidgetTree.h"
#include "TextBlock.h"

void UControlsButton::OnButtonReleased()
{
	switch (ButtonType)
	{
	case RESET:
		ControlsMenuRef->ResetKeyBindings();
		break;

	case BACK_TO_OPTIONS:
		ControlsMenuRef->FadeOut();
		break;

	default:
		break;
	}
}

void UControlsButton::OnButtonHovered()
{
	// Highlight button
	Cast<UTextBlock>(WidgetTree->FindWidget(FName("Text")))->SetOpacity(1.0f);
}

void UControlsButton::OnButtonUnhovered()
{
	// Unhighlight button
	Cast<UTextBlock>(WidgetTree->FindWidget(FName("Text")))->SetOpacity(0.8f);
}
