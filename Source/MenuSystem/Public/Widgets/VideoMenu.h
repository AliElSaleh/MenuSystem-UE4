// Copyright Ali El Saleh 2019

#pragma once

#include "MenuBase.h"
#include "VideoMenu.generated.h"

/**
 * Base class for a video menu widget blueprint
 */
UCLASS()
class MENUSYSTEM_API UVideoMenu : public UMenuBase
{
	GENERATED_BODY()

protected:
	void NativeConstruct() override;
};
