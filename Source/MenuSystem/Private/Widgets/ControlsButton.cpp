// Copyright Ali El Saleh 2019


#include "ControlsButton.h"
#include "ControlsMenu.h"
#include "WidgetTree.h"
#include "TextBlock.h"
#include "LogStatics.h"
#include "MenuHUD.h"

void UControlsButton::NativeConstruct()
{
	Super::NativeConstruct();

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
	// Error check
	if (IsControlsMenuRefNull())
		return;

	// Highlight button
	Cast<UTextBlock>(WidgetTree->FindWidget(FName("Text")))->SetOpacity(1.0f);
}

void UControlsButton::OnButtonUnhovered()
{
	// Error check
	if (IsControlsMenuRefNull())
		return;

	// Unhighlight button
	Cast<UTextBlock>(WidgetTree->FindWidget(FName("Text")))->SetOpacity(0.8f);
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
