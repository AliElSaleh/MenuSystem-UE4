// Copyright Ali El Saleh 2019


#include "TextureQualitySetting.h"
#include "ComboBoxString.h"

void UTextureQualitySetting::Apply()
{
	GameUserSettings->SetTextureQuality(TextureQualityIndex);
}

void UTextureQualitySetting::ChangeGraphicsSetting(const FString& SelectedItem)
{
	if (SelectedItem == Options[0])
	{
		TextureQualityIndex = 0;
	}
	else if (SelectedItem == Options[1])
	{
		TextureQualityIndex = 1;
	}
	else if (SelectedItem == Options[2])
	{
		TextureQualityIndex = 2;
	}
	else if (SelectedItem == Options[3])
	{
		TextureQualityIndex = 3;
	}
}
