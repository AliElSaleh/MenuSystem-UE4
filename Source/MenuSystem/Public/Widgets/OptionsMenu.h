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

protected:
	void NativeConstruct() override;

	void Forward(EMenuType Menu) override;
	void GoForward() override;
	void Back() override;
	void GoBack() override;

	UPROPERTY(BlueprintReadOnly, Category = "Options Menu")
		FText ButtonTooltipText;
};
