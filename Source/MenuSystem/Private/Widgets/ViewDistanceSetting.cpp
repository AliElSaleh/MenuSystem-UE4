// Copyright Ali El Saleh 2019


#include "ViewDistanceSetting.h"

void UViewDistanceSetting::Apply()
{
	GameUserSettings->SetViewDistanceQuality(ViewDistanceIndex);
}

void UViewDistanceSetting::ChangeGraphicsSetting(const FString& SelectedItem)
{
	if (SelectedItem == Options[0])
	{
		ViewDistanceIndex = 0;
	}
	else if (SelectedItem == Options[1])
	{
		ViewDistanceIndex = 1;
	}
	else if (SelectedItem == Options[2])
	{
		ViewDistanceIndex = 2;	
	}
	else if (SelectedItem == Options[3])
	{
		ViewDistanceIndex = 3;
	}
}
