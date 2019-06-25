// Copyright Ali El Saleh 2019

#pragma once

#include "ButtonBase.h"
#include "ControlsButton.generated.h"

/**
 * Base class of a controls button widget bluprint
 */
UCLASS()
class MENUSYSTEM_API UControlsButton : public UButtonBase
{
	GENERATED_BODY()

public:
	void Init() override;

protected:
	// For button functionality
	void OnButtonReleased() override;

	UPROPERTY(BlueprintReadWrite, Category = "Menu Button")
		class UControlsMenu* ControlsMenu;
};
