// Copyright Ali El Saleh 2019

#pragma once

#include "Blueprint/UserWidget.h"
#include "MenuButton.generated.h"

UENUM()
enum EMenuButtonType
{
	NEW_GAME UMETA(DisplayName = "New Game"),
	CONTINUE UMETA(DisplayName = "Continue"),
	OPTIONS UMETA(DisplayName = "Options"),
	CREDITS UMETA(DisplayName = "Credits"),
	EXIT UMETA(DisplayName = "Exit")
};

/**
 * Base class of a menu button widget blueprint
 */
UCLASS()
class MENUSYSTEM_API UMenuButton : public UUserWidget
{
	GENERATED_BODY()

protected:
	void NativeConstruct() override;

	UFUNCTION(BlueprintCallable, Category = "Events")
		void OnButtonReleased();

	// For tooltip text change
	UFUNCTION(BlueprintCallable, Category = "Events")
		void OnButtonHovered();
	UFUNCTION(BlueprintCallable, Category = "Events")
		void OnButtonUnhovered();

	UPROPERTY(EditInstanceOnly, Category = "Menu Button")
		TEnumAsByte<EMenuButtonType> ButtonType;

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "Menu Button")
		FText ButtonText;

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "Menu Button")
		FText ButtonTooltipText;

	UPROPERTY(BlueprintReadWrite, Category = "Menu Button")
		class UMainMenu* MainMenuRef;

private:
	class AMenuHUD* MenuHUD;
};
