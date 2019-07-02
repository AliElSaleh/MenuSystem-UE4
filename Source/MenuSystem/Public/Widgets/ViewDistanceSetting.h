// Copyright Ali El Saleh 2019

#pragma once

#include "Widgets/GraphicsSetting.h"
#include "ViewDistanceSetting.generated.h"

/**
 * Manages the view distance quality of the game
 */
UCLASS()
class MENUSYSTEM_API UViewDistanceSetting final : public UGraphicsSetting
{
	GENERATED_BODY()

public:
	void Apply() override;

protected:
	void ChangeGraphicsSetting(const FString& SelectedItem) override;

private:
	int32 ViewDistanceIndex;
};
