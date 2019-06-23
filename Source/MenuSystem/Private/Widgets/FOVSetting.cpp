// Copyright Ali El Saleh 2019


#include "FOVSetting.h"
#include "Kismet/GameplayStatics.h"

void UFOVSetting::ChangeFOVSetting(const int32 Value)
{
	CurrentFOV = Value;
}

void UFOVSetting::Apply()
{
	UGameplayStatics::GetPlayerCameraManager(GetWorld(), 0)->SetFOV(CurrentFOV);
}
