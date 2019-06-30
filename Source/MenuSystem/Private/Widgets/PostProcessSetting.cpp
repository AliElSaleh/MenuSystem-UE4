// Copyright Ali El Saleh 2019


#include "PostProcessSetting.h"

void UPostProcessSetting::Apply()
{
	GameUserSettings->SetPostProcessingQuality(PostProcessQualityIndex);
}

void UPostProcessSetting::ChangeGraphicsSetting(const FString& SelectedItem)
{
	if (SelectedItem == Options[0])
	{
		PostProcessQualityIndex = 0;
	}
	else if (SelectedItem == Options[1])
	{
		PostProcessQualityIndex = 1;
	}
	else if (SelectedItem == Options[2])
	{
		PostProcessQualityIndex = 2;
	}
	else if (SelectedItem == Options[3])
	{
		PostProcessQualityIndex = 3;
	}
}
