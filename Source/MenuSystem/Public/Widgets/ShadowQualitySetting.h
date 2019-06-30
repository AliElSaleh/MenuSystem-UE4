// Copyright Ali El Saleh 2019

#pragma once

#include "Widgets/GraphicsSetting.h"
#include "ShadowQualitySetting.generated.h"

/**
 * Manages the shadow resolution of the game
 */
UCLASS()
class MENUSYSTEM_API UShadowQualitySetting final : public UGraphicsSetting
{
	GENERATED_BODY()

public:
	void Apply() override;

protected:
	void ChangeGraphicsSetting(const FString& SelectedItem) override;

private:
	int32 ShadowQualityIndex;
};
