// Copyright Ali El Saleh 2019

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ButtonBase.generated.h"

UENUM()
enum EButtonType
{
	VIDEO UMETA(DisplayName = "Video"),
	AUDIO UMETA(DisplayName = "Audio"),
	CONTROLS UMETA(DisplayName = "Controls"),
	BACK UMETA(DisplayName = "Back")
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

	UPROPERTY(BlueprintReadWrite, Category = "Menu Button")
		class UOptionsMenu* OptionsMenuRef;

	class AMenuHUD* MenuHUD;
};
