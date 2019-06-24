// Copyright Ali El Saleh 2019

#pragma once

#include "Blueprint/UserWidget.h"
#include "MenuBase.h"
#include "MainMenu.generated.h"

/**
 * Base class of a main menu widget blueprint
 */
UCLASS()
class MENUSYSTEM_API UMainMenu final : public UMenuBase
{
	GENERATED_BODY()

public:
	void Init() override;
	void InitializeButtons() override;

	UFUNCTION(BlueprintCallable)
		void SetMenuTooltipText(const FText& Text);

	void SlideOut();

	void Forward(EButtonType Button) override;
	void GoForward() override;

protected:
	UPROPERTY(BlueprintReadWrite, Category = "Animations")
		UWidgetAnimation* Slide{};

	UPROPERTY(BlueprintReadOnly, Category = "Main Menu")
		FText ButtonTooltipText;
};
