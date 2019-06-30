// Copyright Ali El Saleh 2019

#pragma once

#include "Widgets/VideoSetting.h"
#include "TextureQualitySetting.generated.h"

/**
 * Manages the texture quality of the game
 */
UCLASS()
class MENUSYSTEM_API UTextureQualitySetting final : public UVideoSetting
{
	GENERATED_BODY()

public:
	void Apply() override;

protected:
	UFUNCTION(BlueprintCallable, Category = "Texture Quality Setting")
		void ChangeTextureQuality(const FString& SelectedItem);
	
	UFUNCTION(BlueprintCallable, Category = "Texture Quality Setting")
		void PopulateList(class UComboBoxString* DropDownList);
	
	UFUNCTION(BlueprintCallable, Category = "Texture Quality Setting")
		void SetSelectedOption(class UComboBoxString* DropDownList);

	UPROPERTY(EditInstanceOnly, Category = "Texture Quality Setting")
		int32 SelectedIndex;

	UPROPERTY(EditInstanceOnly, Category = "Texture Quality Setting")
		TArray<FString> Options;

private:
	int32 TextureQualityIndex;
};
