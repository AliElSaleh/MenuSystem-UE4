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

	void SlideOut();

	void Forward(EButtonType Button) override;

protected:
	UFUNCTION()
		void Remove();

	void GoForward() override;

	UPROPERTY(BlueprintReadWrite, Category = "Animations")
		UWidgetAnimation* Slide{};

private:
	FTimerHandle Timer;
};
