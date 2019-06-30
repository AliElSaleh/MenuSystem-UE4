// Copyright Ali El Saleh 2019


#include "EffectsQualitySetting.h"

void UEffectsQualitySetting::Apply()
{
	GameUserSettings->SetVisualEffectQuality(EffectsQualityIndex);
}

void UEffectsQualitySetting::ChangeGraphicsSetting(const FString& SelectedItem)
{
	if (SelectedItem == Options[0])
	{
		EffectsQualityIndex = 0;
	}
	else if (SelectedItem == Options[1])
	{
		EffectsQualityIndex = 1;
	}
	else if (SelectedItem == Options[2])
	{
		EffectsQualityIndex = 2;
	}
	else if (SelectedItem == Options[3])
	{
		EffectsQualityIndex = 3;
	}
}
