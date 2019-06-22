// Copyright Ali El Saleh 2019

#include "Public/MenuGameMode.h"
#include "MenuPawn.h"
#include "MenuHUD.h"

AMenuGameMode::AMenuGameMode()
{
	DefaultPawnClass = AMenuPawn::StaticClass();
	HUDClass = AMenuHUD::StaticClass();
}
