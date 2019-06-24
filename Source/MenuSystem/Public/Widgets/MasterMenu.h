// Copyright Ali El Saleh 2019

#pragma once

#include "Widgets/MenuBase.h"
#include "MasterMenu.generated.h"

/**
 * Contains all menus and switches between them
 */
UCLASS()
class MENUSYSTEM_API UMasterMenu final : public UMenuBase
{
	GENERATED_BODY()

public:
	void Init() override;

	UMenuBase* GetMenu(int32 Index) const;
	TArray<UMenuBase*> GetMenus() const;

	UWidget* GetCurrentMenuWidget() const;
	int32 GetCurrentMenuIndex() const;

	void SwitchToMenu(UMenuBase* Menu);
	void SwitchToMenuIndex(int32 Index);

protected:
	TArray<UMenuBase*> GetAllChildMenus() const;

	class UWidgetSwitcher* WidgetSwitcher;

	TArray<UMenuBase*> Menus;
};
