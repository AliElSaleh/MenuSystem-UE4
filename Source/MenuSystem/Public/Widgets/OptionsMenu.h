// Copyright Ali El Saleh 2019

#pragma once

#include "Blueprint/UserWidget.h"
#include "MenuBase.h"
#include "OptionsMenu.generated.h"

/**
 * Base class of an options menu widget blueprint
 */
UCLASS()
class MENUSYSTEM_API UOptionsMenu : public UMenuBase
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable)
		void SetOptionsTooltipText(const FText& Text);

	bool bControlsSelected{};
	bool bVideoSelected{};
	bool bAudioSelected{};

protected:
	void NativeConstruct() override;

	void OnAnimationFinished_Implementation(const UWidgetAnimation* Animation) override;

	UPROPERTY(BlueprintReadOnly, Category = "Main Menu")
		FText ButtonTooltipText;
};
