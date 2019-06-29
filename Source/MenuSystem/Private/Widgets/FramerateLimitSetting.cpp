// Copyright Ali El Saleh 2019


#include "FramerateLimitSetting.h"
#include "ComboBoxString.h"

void UFramerateLimitSetting::Apply()
{
	GameUserSettings->SetFrameRateLimit(NewFrameRateLimit);
}

void UFramerateLimitSetting::ChangeFrameRate(const FString& SelectedItem)
{
	for (auto Item : Items)
	{
		if (SelectedItem == Item)
		{
			if (Item == "Unlimited")
			{
				NewFrameRateLimit = 0.0f;
				break;
			}

			const FString SuffixToRemove = "FPS";
			Item.RemoveFromEnd(SuffixToRemove);
			Item.RemoveSpacesInline();

			NewFrameRateLimit = FCString::Atof(*Item);
			break;
		}
	}
}

void UFramerateLimitSetting::PopulateList(UComboBoxString* DropDownList)
{
	for (const auto& Item : Items)
		DropDownList->AddOption(Item);
}

void UFramerateLimitSetting::SetSelectedOption(UComboBoxString* DropDownList)
{
	DropDownList->SetSelectedIndex(SelectedIndex);
}
