// Copyright Ali El Saleh 2019

#include "MasterMenu.h"
#include "WidgetTree.h"
#include "MenuHUD.h"
#include "Components/WidgetSwitcher.h"
#include "Kismet/GameplayStatics.h"
#include "LogStatics.h"

void UMasterMenu::Init()
{
	// Get the Menu HUD
	MenuHUD = Cast<AMenuHUD>(UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetHUD());

	// Get the widget switcher
	WidgetSwitcher = Cast<UWidgetSwitcher>(WidgetTree->FindWidget(FName("MenuSwitcher")));

	Menus = GetAllChildMenus();

	for (auto Menu : Menus)
	{
		Menu->Init();
	}
}

UMenuBase* UMasterMenu::GetMenu(const int32 Index) const
{
	return Menus[Index];
}

TArray<UMenuBase*> UMasterMenu::GetMenus() const
{
	return Menus;
}

UWidget* UMasterMenu::GetCurrentMenuWidget() const
{
	return WidgetSwitcher->GetActiveWidget();
}

int32 UMasterMenu::GetCurrentMenuIndex() const
{
	return WidgetSwitcher->GetActiveWidgetIndex();
}

void UMasterMenu::SwitchToMenu(UMenuBase* Menu)
{
	WidgetSwitcher->SetActiveWidget(Menu);
}

void UMasterMenu::SwitchToMenuIndex(const int32 Index)
{
	WidgetSwitcher->SetActiveWidgetIndex(Index);
}

TArray<UMenuBase*> UMasterMenu::GetAllChildMenus() const
{
	TArray<UMenuBase*> FoundMenus;

	for (auto Menu : WidgetSwitcher->GetAllChildren())
	{
		if (Cast<UMenuBase>(Menu))
			FoundMenus.Add(Cast<UMenuBase>(Menu));
		else
			ULogStatics::LogDebugMessage(WARNING, FString(Menu->GetName() + " is not a UMenuBase"), true);
	}

	return FoundMenus;
}
