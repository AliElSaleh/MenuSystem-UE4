// Copyright Ali El Saleh 2019

#include "NewGameMenu.h"
#include "LogStatics.h"

void UNewGameMenu::NativeConstruct()
{
	Super::NativeConstruct();

	if (!Fade)
		ULogStatics::LogDebugMessage(ERROR, FString("UNewGameMenu::NativeConstruct : Fade anim is null. You forgot to assign the fade animation in widget blueprint"), true);
}
