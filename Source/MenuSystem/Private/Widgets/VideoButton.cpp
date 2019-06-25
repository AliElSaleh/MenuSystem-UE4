// Copyright Ali El Saleh 2019


#include "VideoButton.h"
#include "MenuHUD.h"
#include "VideoMenu.h"
#include "Kismet/GameplayStatics.h"
#include "LogStatics.h"
#include "WidgetTree.h"

void UVideoButton::Init()
{
	Super::Init();

	VideoMenuRef = Cast<UVideoMenu>(MenuHUD->GetMenu(VIDEO_MENU));
}

void UVideoButton::OnButtonReleased()
{
	Super::OnButtonReleased();

	// Error check
	if (IsVideoMenuRefNull())
		return;

	switch (ButtonType)
	{
	case BTN_APPLY:
		VideoMenuRef->Apply();
		break;

	case BTN_BACK:
		VideoMenuRef->Back();
		break;

	default:
		break;
	}
}

void UVideoButton::OnButtonHovered()
{
	// Error check
	if (IsVideoMenuRefNull())
		return;

	VideoMenuRef->SetMenuTooltipText(ButtonTooltipText);
}

void UVideoButton::OnButtonUnhovered()
{
	// Error check
	if (IsVideoMenuRefNull())
		return;

	VideoMenuRef->SetMenuTooltipText(FText());
}

bool UVideoButton::IsVideoMenuRefNull() const
{
	if (!VideoMenuRef)
	{
		ULogStatics::LogDebugMessage(ERROR, FString(GetName() + " | VideoMenuRef is null."), true);
		return true;
	}

	return false;
}
