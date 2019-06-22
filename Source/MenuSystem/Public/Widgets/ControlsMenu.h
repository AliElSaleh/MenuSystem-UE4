// Copyright Ali El Saleh 2019

#pragma once

#include "Blueprint/UserWidget.h"
#include "MenuBase.h"
#include "ControlsMenu.generated.h"

/**
 * Base class of a controls widget blueprint
 */
UCLASS()
class MENUSYSTEM_API UControlsMenu : public UMenuBase
{
	GENERATED_BODY()
	
public:
	void ResetKeyBindings();

protected:
	void NativeConstruct() override;

	void OnAnimationFinished_Implementation(const UWidgetAnimation* Animation) override;

	UPROPERTY(BlueprintReadWrite)
		TArray<UUserWidget*> ControlsSlots;
};
