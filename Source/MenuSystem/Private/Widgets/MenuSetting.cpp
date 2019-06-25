// Copyright Ali El Saleh 2019


#include "MenuSetting.h"
#include "MenuHUD.h"
#include "Engine/Engine.h"
#include "Kismet/GameplayStatics.h"

void UMenuSetting::Init()
{
	MenuHUD = Cast<AMenuHUD>(UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetHUD());
	GameUserSettings = GEngine->GetGameUserSettings();
}

void UMenuSetting::Apply()
{
	GameUserSettings->ApplySettings(false);
}
