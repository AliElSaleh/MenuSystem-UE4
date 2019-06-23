// Copyright Ali El Saleh 2019

#pragma once

#include "Widgets/VideoSetting.h"
#include "FOVSetting.generated.h"

/**
 * FOV Setting class manages the Field of View setting
 */
UCLASS()
class MENUSYSTEM_API UFOVSetting final : public UVideoSetting
{
	GENERATED_BODY()

public:
	void Apply() override;

protected:
	UFUNCTION(BlueprintCallable)
		void ChangeFOVSetting(int32 Value);

private:
	int32 DefaultFOV = 90;
	int32 CurrentFOV = 90;
};
