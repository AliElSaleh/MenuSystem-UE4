// Copyright Ali El Saleh 2019

#pragma once

#include "Blueprint/UserWidget.h"
#include "ControlSlot.generated.h"

/**
 * Base class of a control slot widget blueprint
 */
UCLASS()
class MENUSYSTEM_API UControlSlot : public UUserWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "Default")
		bool bIsAxis = false;

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, meta = (ClampMin = "-1.0", ClampMax = "1.0", EditCondition="bIsAxis"), Category = "Default")
		float AxisScale = 1.0f;

	UPROPERTY(BlueprintReadWrite, Category = "Default")
		class UControlsMenu* ControlsMenuRef;

};
