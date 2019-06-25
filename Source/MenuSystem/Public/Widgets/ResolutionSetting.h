// Copyright Ali El Saleh 2019

#pragma once

#include "CoreMinimal.h"
#include "Widgets/VideoSetting.h"
#include "ResolutionSetting.generated.h"

/**
 * Manages the change of screen resolution
 */
UCLASS()
class MENUSYSTEM_API UResolutionSetting final : public UVideoSetting
{
	GENERATED_BODY()

public:
	void Apply() override;

protected:
	UFUNCTION(BlueprintCallable, Category = "Video Setting")
		void ChangeResolution(const FString& SelectedItem);

	UFUNCTION(BlueprintCallable, Category = "Video Setting")
		void PopulateResolutionList(class UComboBoxString* DropDownList);

	UFUNCTION(BlueprintPure, Category = "Video Settings")
		TArray<FString> GetAllSupportedResolutions();

	UPROPERTY(EditInstanceOnly, Category = "Video Setting")
		FString DefaultResolution = FString("1280x720");

private:
	FIntPoint NewResolution;

	FScreenResolutionArray ScreenResolutions;
};
