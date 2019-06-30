// Copyright Ali El Saleh 2019


#include "AntiAliasSetting.h"

void UAntiAliasSetting::Apply()
{
	GameUserSettings->SetAntiAliasingQuality(AntiAliasIndex);
}

void UAntiAliasSetting::ChangeGraphicsSetting(const FString& SelectedItem)
{
	if (SelectedItem == Options[0])
	{
		AntiAliasIndex = 0;
	}
	else if (SelectedItem == Options[1])
	{
		AntiAliasIndex = 1;
	}
	else if (SelectedItem == Options[2])
	{
		AntiAliasIndex = 2;
	}
	else if (SelectedItem == Options[3])
	{
		AntiAliasIndex = 3;
	}
}
