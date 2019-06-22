// Copyright Ali El Saleh 2019

#pragma once

#include "MenuSetting.h"
#include "VideoSetting.generated.h"

/**
 * Base class for any type of video setting
 */
UCLASS()
class MENUSYSTEM_API UVideoSetting : public UMenuSetting
{
	GENERATED_BODY()

protected:
	void Apply() override;

	UFUNCTION(BlueprintCallable, Category = "Video Setting")
		void ChangeResolution(const FString& SelectedItem);

	UFUNCTION(BlueprintCallable, Category = "Video Setting")
		void PopulateResolutionList(class UComboBoxString* DropDownList);

	UPROPERTY(EditInstanceOnly, Category = "Video Setting")
		FString DefaultResolution = FString("1280x720");

private:
	FScreenResolutionArray ScreenResolutions;
};
