// Copyright Ali El Saleh 2019

#pragma once

#include "Widgets/GraphicsSetting.h"
#include "EffectsQualitySetting.generated.h"

/**
 * Manages the visual effects quality of the game
 */
UCLASS()
class MENUSYSTEM_API UEffectsQualitySetting final : public UGraphicsSetting
{
	GENERATED_BODY()

public:
	void Apply() override;

protected:
	void ChangeGraphicsSetting(const FString& SelectedItem) override;

private:
	int32 EffectsQualityIndex;
};
