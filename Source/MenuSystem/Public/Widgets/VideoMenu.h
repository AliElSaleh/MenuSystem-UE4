// Copyright Ali El Saleh 2019

#pragma once

#include "MenuBase.h"
#include "VideoMenu.generated.h"

/**
 * Base class for a video menu widget blueprint
 */
UCLASS()
class MENUSYSTEM_API UVideoMenu final : public UMenuBase
{
	GENERATED_BODY()

public:
	void Init() override;
	void Back() override;

protected:
	void GoBack() override;

	UPROPERTY(BlueprintReadWrite, Category = "Video Menu")
		TArray<class UVideoSetting*> VideoSettings;
};
