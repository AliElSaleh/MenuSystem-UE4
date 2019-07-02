// Copyright Ali El Saleh 2019


#include "FoliageQualitySetting.h"

void UFoliageQualitySetting::Apply()
{
	GameUserSettings->SetFoliageQuality(FoliageQualityIndex);
}

void UFoliageQualitySetting::ChangeGraphicsSetting(const FString& SelectedItem)
{
	if (SelectedItem == Options[0])
	{
		FoliageQualityIndex = 0;
	}
	else if (SelectedItem == Options[1])
	{
		FoliageQualityIndex = 1;
	}
	else if (SelectedItem == Options[2])
	{
		FoliageQualityIndex = 2;
	}
	else if (SelectedItem == Options[3])
	{
		FoliageQualityIndex = 3;
	}
}
