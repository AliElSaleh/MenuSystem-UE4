// Copyright Ali El Saleh 2019


#include "GraphicsSetting.h"
#include "ComboBoxString.h"

void UGraphicsSetting::ChangeGraphicsSetting(const FString& SelectedItem)
{
}

void UGraphicsSetting::PopulateList(UComboBoxString* DropDownList)
{
	for (const auto& Option : Options)
	{
		DropDownList->AddOption(Option);
	}
}

void UGraphicsSetting::SetSelectedOption(UComboBoxString* DropDownList)
{
	DropDownList->SetSelectedIndex(SelectedIndex);
}
