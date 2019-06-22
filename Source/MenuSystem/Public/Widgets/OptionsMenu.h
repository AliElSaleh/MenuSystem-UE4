// Copyright Ali El Saleh 2019

#pragma once

#include "Blueprint/UserWidget.h"
#include "OptionsMenu.generated.h"

/**
 * Base class of an options menu widget blueprint
 */
UCLASS()
class MENUSYSTEM_API UOptionsMenu : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable)
		void SetOptionsTooltipText(const FText& Text);
	
	void FadeIn();
	void FadeOut();

	bool bControlsSelected{};
	bool bVideoSelected{};
	bool bAudioSelected{};

protected:
	void NativeConstruct() override;

	void OnAnimationStarted_Implementation(const UWidgetAnimation* Animation) override;
	void OnAnimationFinished_Implementation(const UWidgetAnimation* Animation) override;
	
	UPROPERTY(BlueprintReadWrite, Category = "Animations")
		UWidgetAnimation* Fade;

	UPROPERTY(BlueprintReadOnly, Category = "Main Menu")
		FText ButtonTooltipText;

private:
	class AMenuHUD* MenuHUD;
};
