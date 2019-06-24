// Copyright Ali El Saleh 2019

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ButtonBase.generated.h"


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

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "Menu Button")
		FText ButtonText;

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "Menu Button")
		FText ButtonTooltipText;

	class AMenuHUD* MenuHUD;
};
