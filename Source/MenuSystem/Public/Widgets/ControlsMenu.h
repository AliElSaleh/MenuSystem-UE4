// Copyright Ali El Saleh 2019

#pragma once

#include "Blueprint/UserWidget.h"
#include "ControlsMenu.generated.h"

/**
 * Base class of a controls widget blueprint
 */
UCLASS()
class MENUSYSTEM_API UControlsMenu : public UUserWidget
{
	GENERATED_BODY()
	
public:
	void FadeIn();
	void FadeOut();

	void ResetKeyBindings();

protected:
	void NativeConstruct() override;

	void OnAnimationStarted_Implementation(const UWidgetAnimation* Animation) override;
	void OnAnimationFinished_Implementation(const UWidgetAnimation* Animation) override;

	UPROPERTY(BlueprintReadWrite)
		UWidgetAnimation* Fade;

	UPROPERTY(BlueprintReadWrite)
		TArray<UUserWidget*> ControlsSlots;

private:
	class AMenuHUD* MenuHUD;
};
