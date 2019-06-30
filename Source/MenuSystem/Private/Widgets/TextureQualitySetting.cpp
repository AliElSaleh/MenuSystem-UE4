// Copyright Ali El Saleh 2019


#include "TextureQualitySetting.h"
#include "ComboBoxString.h"

void UTextureQualitySetting::Apply()
{
	GameUserSettings->SetTextureQuality(SelectedIndex);
}

void UTextureQualitySetting::ChangeTextureQuality(const FString& SelectedItem)
{
	if (SelectedItem == Options[0])
	{
		SelectedIndex = 0;
	}
	else if (SelectedItem == Options[1])
	{
		SelectedIndex = 1;
	}
	else if (SelectedItem == Options[2])
	{
		SelectedIndex = 2;
	}
	else if (SelectedItem == Options[3])
	{
		SelectedIndex = 3;
	}
}

void UTextureQualitySetting::PopulateList(UComboBoxString* DropDownList)
{
	for (const auto& Option : Options)
	{
		DropDownList->AddOption(Option);
	}
}

void UTextureQualitySetting::SetSelectedOption(UComboBoxString* DropDownList)
{
	DropDownList->SetSelectedIndex(SelectedIndex);
}
