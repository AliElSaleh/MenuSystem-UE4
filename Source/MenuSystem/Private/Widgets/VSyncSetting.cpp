// Copyright Ali El Saleh 2019


#include "VSyncSetting.h"
#include "ComboBoxString.h"

void UVSyncSetting::Apply()
{
	GameUserSettings->bUseVSync = bVSyncEnabled;
	GameUserSettings->SetVSyncEnabled(bVSyncEnabled);
}

void UVSyncSetting::PopulateList(UComboBoxString* DropDownList)
{
	DropDownList->AddOption(FString("On"));
	DropDownList->AddOption(FString("Off"));
}

void UVSyncSetting::SetSelectedOption(UComboBoxString* DropDownList, const bool bEnabled)
{
	if (bEnabled)
	{
		bVSyncEnabled = true;
		DropDownList->SetSelectedOption("On");
	}
	else
	{
		bVSyncEnabled = false;
		DropDownList->SetSelectedOption("Off");
	}
}

void UVSyncSetting::ChangeVSyncSetting(const FString& Selection)
{
	if (Selection == "On")
	{	
		bVSyncEnabled = true;
	}
	else
	{
		bVSyncEnabled = false;
	}
}
