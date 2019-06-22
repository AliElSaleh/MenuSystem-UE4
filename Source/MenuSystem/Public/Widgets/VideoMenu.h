// Copyright Ali El Saleh 2019

#pragma once

#include "Blueprint/UserWidget.h"
#include "VideoMenu.generated.h"

/**
 * Base class for a video menu widget blueprint
 */
UCLASS()
class MENUSYSTEM_API UVideoMenu : public UUserWidget
{
	GENERATED_BODY()
	
public:
	void FadeIn();
	void FadeOut();

protected:
	void NativeConstruct() override;

	void OnAnimationStarted_Implementation(const UWidgetAnimation* Animation) override;
	void OnAnimationFinished_Implementation(const UWidgetAnimation* Animation) override;

	UPROPERTY(BlueprintReadWrite, Category = "Animations")
		UWidgetAnimation* Fade;

private:
	class AMenuHUD* MenuHUD;
};
