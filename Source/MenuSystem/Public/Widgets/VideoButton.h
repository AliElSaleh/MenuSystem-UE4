// Copyright Ali El Saleh 2019

#pragma once

#include "Widgets/ButtonBase.h"
#include "VideoButton.generated.h"

/**
 * A button that lives in a video menu widget
 */
UCLASS()
class MENUSYSTEM_API UVideoButton final : public UButtonBase
{
	GENERATED_BODY()

public:
	void Init() override;

protected:
	// For button functionality
	void OnButtonReleased() override;

private:
	bool IsVideoMenuRefNull() const;

	class UVideoMenu* VideoMenuRef;
};
