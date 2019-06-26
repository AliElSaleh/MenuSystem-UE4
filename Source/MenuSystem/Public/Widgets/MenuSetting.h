// Copyright Ali El Saleh 2019

#pragma once

#include "Blueprint/UserWidget.h"
#include "GameFramework/GameUserSettings.h"
#include "MenuSetting.generated.h"

/**
 * Base class for any menu setting type
 */
UCLASS()
class MENUSYSTEM_API UMenuSetting : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void Apply();
	virtual void Init();

	void SetMenuReference(class UMenuBase* InMenu);

protected:
	void NativeOnMouseEnter(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
	void NativeOnMouseLeave(const FPointerEvent& InMouseEvent) override;

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category = "Video Setting")
		FText SettingLabel;

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category = "Video Setting")
		FText SettingTooltipText;

	class UGameUserSettings* GameUserSettings;
	class AMenuHUD* MenuHUD;
	class UMenuBase* Menu;
};
