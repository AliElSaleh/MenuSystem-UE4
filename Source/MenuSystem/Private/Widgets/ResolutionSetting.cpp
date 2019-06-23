// Copyright Ali El Saleh 2019


#include "ResolutionSetting.h"
#include "GameFramework/GameUserSettings.h"
#include "Components/ComboBoxString.h"
#include "VideoMenu.h"
#include "Engine/Engine.h"
#include "LogStatics.h"

void UResolutionSetting::ChangeResolution(const FString& SelectedItem)
{
	// Get the selected resolution string and split it up
	FString XRes;
	FString YRes;
	SelectedItem.Split(FString("x"), &XRes, &YRes);

	// Once split, convert strings into integers
	const int32 X = FCString::Atoi(*XRes);
	const int32 Y = FCString::Atoi(*YRes);

	// Set the new resolution
	NewResolution = FIntPoint(X, Y);
}

void UResolutionSetting::PopulateResolutionList(UComboBoxString* DropDownList)
{
	// Get every resolution supported
	RHIGetAvailableResolutions(ScreenResolutions, true);

	// Populate the combo box
	for (int32 i = ScreenResolutions.Num() - 1; i >= 0; i--)
	{
		FString Option = FString::FromInt(ScreenResolutions[i].Width) + "x" + FString::FromInt(ScreenResolutions[i].Height);

		DropDownList->AddOption(Option);
	}

	// Set the default resolution as the selected option
	DropDownList->SetSelectedOption(DefaultResolution);
}

void UResolutionSetting::Init()
{
	Super::Init();
}

void UResolutionSetting::Apply()
{
	GEngine->GetGameUserSettings()->SetFullscreenMode(EWindowMode::Windowed);
	GEngine->GetGameUserSettings()->SetScreenResolution(NewResolution);
	GEngine->GetGameUserSettings()->ApplySettings(false);
}
