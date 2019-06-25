// Copyright Ali El Saleh 2019

#pragma once

#include "Blueprint/UserWidget.h"
#include "MenuBase.h"
#include "ControlsMenu.generated.h"

/**
 * Base class of a controls widget blueprint
 */
UCLASS()
class MENUSYSTEM_API UControlsMenu final : public UMenuBase
{
	GENERATED_BODY()
	
public:
	void ResetKeyBindings();

	void Init() override;

	void Back() override;
	void GoBack() override;

protected:
	UPROPERTY(BlueprintReadWrite)
		TArray<UUserWidget*> ControlsSlots;
};
