// Copyright Ali El Saleh 2019

#pragma once

#include "ButtonBase.h"
#include "OptionsButton.generated.h"

/**
 * Base class of an options button widget blueprint
 */
UCLASS()
class MENUSYSTEM_API UOptionsButton : public UButtonBase
{
	GENERATED_BODY()

protected:
	// For button functionality
	void OnButtonReleased() override;

	// For tooltip text change
	void OnButtonHovered() override;
	void OnButtonUnhovered() override;
};
