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

public:
	void Init() override;

protected:
	TArray<UVideoSetting*> Settings;
		
	class UVideoMenu* VideoMenuRef;
};
