// Copyright Ali El Saleh 2019

#include "VideoMenu.h"
#include "LogStatics.h"

void UVideoMenu::NativeConstruct()
{
	Super::NativeConstruct();
	
	if (!Fade)
		ULogStatics::LogDebugMessage(ERROR, FString("UVideoMenu::NativeConstruct : Fade anim is null. You forgot to assign the fade animation in widget blueprint"), true);
}
