// Copyright Ali El Saleh 2019

#pragma once

#include "ButtonBase.h"
#include "MenuButton.generated.h"

/**
 * Base class of a menu button widget blueprint
 */
UCLASS()
class MENUSYSTEM_API UMenuButton : public UButtonBase
{
	GENERATED_BODY()

protected:
	void NativeConstruct() override;

	// For button functionality
	void OnButtonReleased() override;

	// For tooltip text change
	void OnButtonHovered() override;
	void OnButtonUnhovered() override;

	UPROPERTY(BlueprintReadWrite, Category = "Menu Button")
		class UMainMenu* MainMenuRef;

	
	UPROPERTY(EditInstanceOnly, Category = "Menu Button")
		TEnumAsByte<enum EMenuType> ButtonType;

private:
	bool IsMainMenuRefNull() const;
};
