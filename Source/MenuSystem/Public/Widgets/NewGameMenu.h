// Copyright Ali El Saleh 2019

#pragma once

#include "Blueprint/UserWidget.h"
#include "NewGameMenu.generated.h"

/**
 * Base class of a new game widget blueprint
 */
UCLASS()
class MENUSYSTEM_API UNewGameMenu : public UUserWidget
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
