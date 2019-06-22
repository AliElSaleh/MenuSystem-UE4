// Copyright Ali El Saleh 2019

#pragma once

#include "Blueprint/UserWidget.h"
#include "OptionsButton.generated.h"

UENUM()
enum EOptionButtonType
{
	VIDEO UMETA(DisplayName = "Video"),
	AUDIO UMETA(DisplayName = "Audio"),
	CONTROLS UMETA(DisplayName = "Controls"),
	BACK UMETA(DisplayName = "Back")
};

/**
 * Base class of an options button widget blueprint
 */
UCLASS()
class MENUSYSTEM_API UOptionsButton : public UUserWidget
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
		TEnumAsByte<EOptionButtonType> ButtonType;

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "Menu Button")
		FText ButtonText;

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "Menu Button")
		FText ButtonTooltipText;

	UPROPERTY(BlueprintReadWrite, Category = "Menu Button")
		class UOptionsMenu* OptionsMenuRef;

private:
	class AMenuHUD* MenuHUD;
};
