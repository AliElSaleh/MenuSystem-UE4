// Copyright Ali El Saleh 2019

#pragma once

#include "Widgets/ButtonBase.h"
#include "AudioButton.generated.h"

/**
 * A button that lives within an audio menu widget
 */
UCLASS()
class MENUSYSTEM_API UAudioButton final : public UButtonBase
{
	GENERATED_BODY()
	
public:
	void Init() override;

protected:
	// For button functionality
	void OnButtonReleased() override;

private:
	class UAudioMenu* AudioMenu;
};
