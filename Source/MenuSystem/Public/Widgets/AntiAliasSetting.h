// Copyright Ali El Saleh 2019

#pragma once

#include "Widgets/GraphicsSetting.h"
#include "AntiAliasSetting.generated.h"

/**
 * Manages the anti-aliasing setting of the game
 */
UCLASS()
class MENUSYSTEM_API UAntiAliasSetting final : public UGraphicsSetting
{
	GENERATED_BODY()
	
public:
	void Apply() override;

protected:
	void ChangeGraphicsSetting(const FString& SelectedItem) override;

private:
	int32 AntiAliasIndex;
};
