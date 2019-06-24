// Copyright Ali El Saleh 2019

#pragma once

#include "Blueprint/UserWidget.h"
#include "MenuBase.h"
#include "OptionsMenu.generated.h"

/**
 * Base class of an options menu widget blueprint
 */
UCLASS()
class MENUSYSTEM_API UOptionsMenu final : public UMenuBase
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable)
		void SetOptionsTooltipText(const FText& Text);

	void Forward(EButtonType Menu) override;
	void Back() override;

protected:
	void NativeConstruct() override;

	void GoForward() override;
	void GoBack() override;

	UPROPERTY(BlueprintReadOnly, Category = "Options Menu")
		FText ButtonTooltipText;
};
