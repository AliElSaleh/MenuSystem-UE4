// Copyright Ali El Saleh 2019

#pragma once

#include "ButtonBase.h"
#include "OptionsButton.generated.h"

/**
 * Base class of an options button widget blueprint
 */
UCLASS()
class MENUSYSTEM_API UOptionsButton final : public UButtonBase
{
	GENERATED_BODY()

public:
	void Init() override;

protected:
	// For button functionality
	void OnButtonReleased() override;

private:
	class UOptionsMenu* OptionsMenu;
};
