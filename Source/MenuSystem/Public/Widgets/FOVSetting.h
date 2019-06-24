// Copyright Ali El Saleh 2019

#pragma once

#include "Widgets/VideoSetting.h"
#include "FOVSetting.generated.h"

/**
 * Manages the Field of View setting
 */
UCLASS()
class MENUSYSTEM_API UFOVSetting final : public UVideoSetting
{
	GENERATED_BODY()

public:
	void Apply() override;

protected:
	void NativePreConstruct() override;

	UFUNCTION(BlueprintCallable)
		void ChangeFOVSetting(float SliderValue, bool bApplyOnChange);

	UFUNCTION(BlueprintPure)
		float GetSliderValueAtDefaultFOV();

	UFUNCTION(BlueprintPure)
		float GetSliderValueAtFOV(int32 Value);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "FOV")
		int32 CurrentFOV = 90;

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "FOV")
		int32 MinFOV = 70;

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "FOV")
		int32 MaxFOV = 120;
	
	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "FOV")
		int32 DefaultFOV = 90;
};
