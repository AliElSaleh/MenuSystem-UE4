// Copyright Ali El Saleh 2019

#pragma once

#include "Widgets/VideoSetting.h"
#include "VSyncSetting.generated.h"

/**
 * Manages the V-Sync setting of the game
 */
UCLASS()
class MENUSYSTEM_API UVSyncSetting final : public UVideoSetting
{
	GENERATED_BODY()

public:
	void Apply() override;

protected:
	UFUNCTION(BlueprintCallable, Category = "V-Sync Setting")
		void PopulateList(class UComboBoxString* DropDownList);

	UFUNCTION(BlueprintCallable, Category = "V-Sync Setting")
		void SetSelectedOption(UComboBoxString* DropDownList);

	UFUNCTION(BlueprintCallable, Category = "V-Sync Setting")
		void ChangeVSyncSetting(const FString& Selection);

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category = "V-Sync Setting")
		int32 SelectedIndex;

	UPROPERTY(EditInstanceOnly, Category = "V-Sync Setting")
		TArray<FString> Options;

private:
	bool bVSyncEnabled;
};
