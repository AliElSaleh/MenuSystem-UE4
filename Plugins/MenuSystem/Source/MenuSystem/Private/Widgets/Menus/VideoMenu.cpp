// Copyright Ali El Saleh 2019

#include "VideoMenu.h"
#include "GameFramework/GameUserSettings.h"
#include "MenuHUD.h"
#include "OptionsMenu.h"
#include "WidgetTree.h"
#include "TextBlock.h"
#include "VideoSetting.h"
#include "CanvasPanel.h"

void UVideoMenu::Init()
{
	Super::Init();

	ConfirmationBox = Cast<UCanvasPanel>(WidgetTree->FindWidget(FName("ConfirmationBox")));
	ResetWarningBox = Cast<UCanvasPanel>(WidgetTree->FindWidget(FName("ResetWarningBox")));

	InitializeSettings();

	HideWidgets();

	Apply();
}

void UVideoMenu::ShowResetWarning()
{
	ResetWarningBox->SetVisibility(ESlateVisibility::Visible);
}

void UVideoMenu::HideResetWarning()
{
	ResetWarningBox->SetVisibility(ESlateVisibility::Hidden);
}

void UVideoMenu::HideWidgets()
{
	ConfirmationBox->SetVisibility(ESlateVisibility::Hidden);
	ResetWarningBox->SetVisibility(ESlateVisibility::Hidden);
}

void UVideoMenu::Back()
{
	if (AnyUnsavedChanges())
	{
		// Show the message box
		ConfirmationBox->SetVisibility(ESlateVisibility::Visible);

		// Generate the message based on the number of settings changed
		FString NewMessage;
		const int32 Changes = ChangedSettings.Num();
		if (Changes > 1)
			NewMessage = FString("There are ") + FString::FromInt(Changes) + FString(" unsaved changes. Do you want to apply these changes?");
		else
			NewMessage = FString("There is ") + FString::FromInt(Changes) + FString(" unsaved change. Do you want to apply this change?");

		// Set the generated message
		//const auto MessageBox = Cast<UTextBlock>(ConfirmationBox->GetChildAt(4));
		//MessageBox->SetText(FText::FromString(NewMessage));

		// Back out, because we don't want to return to the options menu yet.
		return;
	}

	// Hide this menu
	MenuHUD->HideMenu(StaticClass());
	Super::Back();
}

void UVideoMenu::GoBack()
{
	// Switch to the options menu
	MenuHUD->ShowMenu(3);
	Super::GoBack();
}

void UVideoMenu::Apply()
{
	Super::Apply();

	// This is when we're in the confirmation box
	if (ChangedSettings.Num() > 0)
	{
		ConfirmationBox->SetVisibility(ESlateVisibility::Hidden);

		MenuHUD->HideMenu(StaticClass());
		Super::Back();
	}

	ChangedSettings.Empty();
}

void UVideoMenu::DiscardChanges()
{
	// Go through all changed settings
	for (auto Setting : ChangedSettings)
	{
		// Revert to previous applied setting
		Setting->RevertChange();
	}

	// Hide the message box
	ConfirmationBox->SetVisibility(ESlateVisibility::Hidden);

	// Discard the entire array
	ChangedSettings.Empty();

	// Apply the changes
	Super::Apply();

	// Hide this menu
	MenuHUD->HideMenu(StaticClass());
	Super::Back();
}

bool UVideoMenu::AnyUnsavedChanges()
{
	// Go through each setting in this menu
	for (auto Setting : MenuSettings)
	{
		// Add settings that have been changed
		if (Setting->HasChanged())
		{
			//ULog::DebugMessage(INFO, Setting->GetName() + FString(" has changed"), true);
			ChangedSettings.Add(Setting);
		}
	}
	
	//ULog::DebugMessage(INFO, FString::FromInt(ChangedSettings.Num()) + FString(" changes found"), true);

	// Return true if at least 1 setting has been changed, otherwise return false
	return ChangedSettings.Num() > 0;
}

