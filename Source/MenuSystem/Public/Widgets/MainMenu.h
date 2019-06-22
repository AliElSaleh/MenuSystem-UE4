// Copyright Ali El Saleh 2019

#pragma once

#include "Blueprint/UserWidget.h"
#include "MainMenu.generated.h"

/**
 * Base class of a main menu widget blueprint
 */
UCLASS()
class MENUSYSTEM_API UMainMenu : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
		void SetMenuTooltipText(const FText& Text);

	void FadeIn();
	void FadeOut();

	void SlideOut();

	bool bNewGameSelected{};
	bool bOptionsSelected{};
protected:
	void NativeConstruct() override;

	void OnAnimationStarted_Implementation(const UWidgetAnimation* Animation) override;
	void OnAnimationFinished_Implementation(const UWidgetAnimation* Animation) override;

	UPROPERTY(BlueprintReadWrite, Category = "Animations")
		UWidgetAnimation* Fade;

	UPROPERTY(BlueprintReadWrite, Category = "Animations")
		UWidgetAnimation* Slide;

	UPROPERTY(BlueprintReadOnly, Category = "Main Menu")
		FText ButtonTooltipText;

private:
	class AMenuHUD* MenuHUD;
};
