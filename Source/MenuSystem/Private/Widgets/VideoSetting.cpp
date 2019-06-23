// Copyright Ali El Saleh 2019


#include "VideoSetting.h"
#include "MenuHUD.h"
#include "VideoMenu.h"

void UVideoSetting::Init()
{
	Super::Init();

	VideoMenuRef = Cast<UVideoMenu>(MenuHUD->GetMenu(VIDEO_MENU));
}
