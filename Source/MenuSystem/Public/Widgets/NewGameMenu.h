// Copyright Ali El Saleh 2019

#pragma once

#include "MenuBase.h"
#include "NewGameMenu.generated.h"

/**
 * Base class of a new game widget blueprint
 */
UCLASS()
class MENUSYSTEM_API UNewGameMenu : public UMenuBase
{
	GENERATED_BODY()

protected:
	void NativeConstruct() override;
};
