// Copyright Ali El Saleh 2019

#pragma once

#include "GraphicsSetting.h"
#include "TextureQualitySetting.generated.h"

/**
 * Manages the texture quality of the game
 */
UCLASS()
class MENUSYSTEM_API UTextureQualitySetting final : public UGraphicsSetting
{
	GENERATED_BODY()

public:
	void Apply() override;

protected:
	void ChangeGraphicsSetting(const FString& SelectedItem) override;

private:
	int32 TextureQualityIndex;
};
