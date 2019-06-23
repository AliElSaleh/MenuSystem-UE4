// Copyright Ali El Saleh 2019

#pragma once

#include "CoreMinimal.h"
#include "Widgets/VideoSetting.h"
#include "ResolutionSetting.generated.h"

/**
 * Resolution setting class manages the change of the screen resolution
 */
UCLASS()
class MENUSYSTEM_API UResolutionSetting : public UVideoSetting
{
	GENERATED_BODY()

public:
	void Init() override;
	void Apply() override;

protected:
	UFUNCTION(BlueprintCallable, Category = "Video Setting")
		void ChangeResolution(const FString& SelectedItem);

	UFUNCTION(BlueprintCallable, Category = "Video Setting")
		void PopulateResolutionList(class UComboBoxString* DropDownList);

	UPROPERTY(EditInstanceOnly, Category = "Video Setting")
		FString DefaultResolution = FString("1280x720");

private:
	FIntPoint NewResolution;

	FScreenResolutionArray ScreenResolutions;
};
