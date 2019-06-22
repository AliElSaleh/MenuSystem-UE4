// Copyright Ali El Saleh 2019

#pragma once

#include "Blueprint/UserWidget.h"
#include "MenuBase.generated.h"

/**
 * Base class for any type of menu widgets i.e (Main, Options, Video, Audio, Input, etc.)  
 */
UCLASS()
class MENUSYSTEM_API UMenuBase : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void FadeIn();
	virtual void FadeOut();

protected:
	void NativeConstruct() override;

	void OnAnimationStarted_Implementation(const UWidgetAnimation* Animation) override;
	void OnAnimationFinished_Implementation(const UWidgetAnimation* Animation) override;

	UPROPERTY(BlueprintReadWrite, Category = "Animations")
		UWidgetAnimation* Fade;

	class AMenuHUD* MenuHUD;
};
