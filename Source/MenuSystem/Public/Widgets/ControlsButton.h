// Copyright Ali El Saleh 2019

#pragma once

#include "Blueprint/UserWidget.h"
#include "ControlsButton.generated.h"

UENUM()
enum EControlsButtonType
{
	RESET UMETA(DisplayName = "Reset"),
	BACK_TO_OPTIONS UMETA(DisplayName = "Back")
};

/**
 * Base class of a controls button widget bluprint
 */
UCLASS()
class MENUSYSTEM_API UControlsButton : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Events")
		void OnButtonReleased();

	// For text highlighting
	UFUNCTION(BlueprintCallable, Category = "Events")
		void OnButtonHovered();
	UFUNCTION(BlueprintCallable, Category = "Events")
		void OnButtonUnhovered();

	UPROPERTY(EditInstanceOnly, Category = "Menu Button")
		TEnumAsByte<EControlsButtonType> ButtonType;

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "Menu Button")
		FText ButtonText;

	UPROPERTY(BlueprintReadWrite, Category = "Menu Button")
		class UControlsMenu* ControlsMenuRef;

private:
	class AMenuHUD* MenuHUD;
};
