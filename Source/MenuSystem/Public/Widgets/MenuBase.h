// Copyright Ali El Saleh 2019

#pragma once

#include "Blueprint/UserWidget.h"
#include "MenuBase.generated.h"

UENUM()
enum EMenuType
{
	MAIN,
	OPTIONS,
	NEW_GAME,
	CONTROLS,
	VIDEO,
	AUDIO,
	CREDITS
};

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

	virtual void Init();

	UFUNCTION(BlueprintCallable)
		virtual void Forward(EMenuType Menu);

	UFUNCTION(BlueprintCallable)
		virtual void Back();

protected:
	void NativeConstruct() override;

	UFUNCTION(BlueprintCallable)
		virtual void Apply();


	UFUNCTION(BlueprintCallable, Category = "Video Menu")
		virtual void StoreAllSettings(class UVerticalBox* ParentWidget);

	virtual void GoForward();
	virtual void GoBack();

	void OnAnimationStarted_Implementation(const UWidgetAnimation* Animation) override;
	void OnAnimationFinished_Implementation(const UWidgetAnimation* Animation) override;

	UPROPERTY(BlueprintReadWrite, Category = "Animations")
		UWidgetAnimation* Fade{};

	EMenuType MenuSelected;

	class AMenuHUD* MenuHUD{};

	FTimerHandle ForwardTimerHandle;
	FTimerHandle BackTimerHandle;
};
