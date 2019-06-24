// Copyright Ali El Saleh 2019

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ButtonBase.generated.h"

UENUM()
enum EButtonType
{
	BTN_NEW_GAME	UMETA(DisplayName="New game"),
	BTN_CONTINUE	UMETA(DisplayName="Continue"),
	BTN_OPTIONS		UMETA(DisplayName="Options"),
	BTN_CREDITS		UMETA(DisplayName="Credits"),
	BTN_VIDEO		UMETA(DisplayName="Video"),
	BTN_AUDIO		UMETA(DisplayName="Audio"),
	BTN_CONTROLS	UMETA(DisplayName="Controls"),
	BTN_BACK		UMETA(DisplayName="Back"),
	BTN_EXIT		UMETA(DisplayName="Exit")
};

/**
 * Base class for a menu button
 */
UCLASS()
class MENUSYSTEM_API UButtonBase : public UUserWidget
{
	GENERATED_BODY()

protected:
	void NativeConstruct() override;

	// For button functionality
	UFUNCTION(BlueprintCallable, Category = "Events")
		virtual void OnButtonReleased();

	// For tooltip text change
	UFUNCTION(BlueprintCallable, Category = "Events")
		virtual void OnButtonHovered();
	UFUNCTION(BlueprintCallable, Category = "Events")
		virtual void OnButtonUnhovered();

	UPROPERTY(EditInstanceOnly, Category = "Menu Button")
		TEnumAsByte<EButtonType> ButtonType;

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "Menu Button")
		FText ButtonText;

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "Menu Button")
		FText ButtonTooltipText;

	class AMenuHUD* MenuHUD;
};
