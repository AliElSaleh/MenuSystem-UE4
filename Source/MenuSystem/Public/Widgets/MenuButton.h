// Copyright Ali El Saleh 2019

#pragma once

#include "ButtonBase.h"
#include "MenuButton.generated.h"

/**
 * Base class of a menu button widget blueprint
 */
UCLASS()
class MENUSYSTEM_API UMenuButton : public UButtonBase
{
	GENERATED_BODY()

public:
	void Init() override;

protected:
	// For button functionality
	void OnButtonReleased() override;

private:
	class UMainMenu* MainMenu;
};
