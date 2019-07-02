// Copyright Ali El Saleh 2019

#pragma once

#include "Widgets/GraphicsSetting.h"
#include "FoliageQualitySetting.generated.h"

/**
 * Manages the foliage quality in the game
 */
UCLASS()
class MENUSYSTEM_API UFoliageQualitySetting final : public UGraphicsSetting
{
	GENERATED_BODY()
	
public:
	void Apply() override;

protected:
	void ChangeGraphicsSetting(const FString& SelectedItem) override;

private:
	int32 FoliageQualityIndex;
};
