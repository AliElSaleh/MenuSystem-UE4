// Copyright Ali El Saleh 2019


#include "ShadowQualitySetting.h"

void UShadowQualitySetting::Apply()
{
	GameUserSettings->SetShadowQuality(ShadowQualityIndex);
}

void UShadowQualitySetting::ChangeGraphicsSetting(const FString& SelectedItem)
{
	if (SelectedItem == Options[0])
	{
		ShadowQualityIndex = 0;
	}
	else if (SelectedItem == Options[1])
	{
		ShadowQualityIndex = 1;
	}
	else if (SelectedItem == Options[2])
	{
		ShadowQualityIndex = 2;
	}
	else if (SelectedItem == Options[3])
	{
		ShadowQualityIndex = 3;
	}
}
