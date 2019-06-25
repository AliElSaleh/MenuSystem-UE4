// Copyright Ali El Saleh 2019

#pragma once

#include "Widgets/MenuBase.h"
#include "AudioMenu.generated.h"

/**
 * Base class for an audio menu widget blueprint
 */
UCLASS()
class MENUSYSTEM_API UAudioMenu final : public UMenuBase
{
	GENERATED_BODY()
	
public:
	void Init() override;

	void Back() override;

protected:
	void GoBack() override;
};
