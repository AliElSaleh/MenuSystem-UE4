// Copyright Ali El Saleh 2019

#include "InputKeyBinding.h"
#include "WidgetTree.h"
#include "InputKeySelector.h"
#include "ControlsMenu.h"
#include "TextBlock.h"
#include "GameFramework/InputSettings.h"

void UInputKeyBinding::Init()
{
	Super::Init();

	// Get access to the input settings
	const auto Input = const_cast<UInputSettings*>(GetDefault<UInputSettings>());

	if (bIsAxis)
	{
		TArray<FInputAxisKeyMapping> OutMappings;
		Input->GetAxisMappingByName(InputName, OutMappings);

		// Setup axis inputs
		for (auto& KeyMapping : OutMappings)
		{
			if (KeyMapping.Scale == Scale && !IsInputAGamepadKey(KeyMapping.Key))
			{
				CurrentPrimaryInput = KeyMapping.Key;
			}
			
			if (KeyMapping.Scale == Scale && IsInputAGamepadKey(KeyMapping.Key))
			{
				CurrentGamepadInput = KeyMapping.Key;
			}
		}
	}
	else
	{
		TArray<FInputActionKeyMapping> OutMappings;
		Input->GetActionMappingByName(InputName, OutMappings);

		// Setup action inputs
		for (const auto& KeyMapping : OutMappings)
		{
			if (!IsInputAGamepadKey(KeyMapping.Key))
			{
				CurrentPrimaryInput = KeyMapping.Key;
			}

			if (IsInputAGamepadKey(KeyMapping.Key))
			{
				CurrentGamepadInput = KeyMapping.Key;
			}
		}
	}

	PrimaryKeySelector = Cast<UInputKeySelector>(WidgetTree->FindWidget(FName("PrimaryKeySelector")));
	GamepadKeySelector = Cast<UInputKeySelector>(WidgetTree->FindWidget(FName("GamepadKeySelector")));

	SetCurrentInput(PrimaryKeySelector, GamepadKeySelector);

	ControlsMenu = Cast<UControlsMenu>(Menu);

	bInitialized = true;
}

void UInputKeyBinding::Reset()
{
	CurrentPrimaryInput = DefaultPrimaryInput;
	CurrentGamepadInput = DefaultGamepadInput;

	SetDefaultInput(PrimaryKeySelector, GamepadKeySelector);
}

bool UInputKeyBinding::IsDefault()
{
	return PrimaryKeySelector->SelectedKey == DefaultPrimaryInput && GamepadKeySelector->SelectedKey == DefaultGamepadInput;
}

void UInputKeyBinding::SetSelectedPrimaryInput()
{
	PrimaryKeySelector->SetSelectedKey(CurrentPrimaryInput);
}

void UInputKeyBinding::SetSelectedGamepadInput()
{
	GamepadKeySelector->SetSelectedKey(CurrentGamepadInput);
}

void UInputKeyBinding::SetDefaultInput(class UInputKeySelector* Primary, class UInputKeySelector* Gamepad)
{
	Primary->SetSelectedKey(DefaultPrimaryInput);
	Gamepad->SetSelectedKey(DefaultGamepadInput);
}

void UInputKeyBinding::SetCurrentInput(UInputKeySelector* Primary, UInputKeySelector* Gamepad)
{
	Primary->SetSelectedKey(CurrentPrimaryInput);
	Gamepad->SetSelectedKey(CurrentGamepadInput);
}

void UInputKeyBinding::SetSelectedPrimaryInput(UInputKeySelector* Primary)
{
	if (!Primary)
		return;

	Primary->SetSelectedKey(CurrentPrimaryInput);
}

void UInputKeyBinding::SetSelectedGamepadInput(UInputKeySelector* Gamepad)
{
	if (!Gamepad)
		return;

	Gamepad->SetSelectedKey(CurrentGamepadInput);
}

void UInputKeyBinding::RebindPrimaryInput(const FInputChord& NewInput)
{
	// Check if it's a gamepad key
	if (IsInputAGamepadKey(NewInput))
	{
		SetSelectedPrimaryInput(PrimaryKeySelector);
		return;
	}

	if (bInitialized)// This is here to prevent a crash when pre-constructing
	{
		// Check if it's a duplicate key with any other bound primary key
		if (ControlsMenu->IsPrimaryInputKeyDuplicate(this, NewInput))
		{
			SetSelectedPrimaryInput(PrimaryKeySelector);
			return;
		}
	}

	// Rebind key
	ControlsMenu->RebindInputMapping(this, CurrentPrimaryInput, NewInput);
			
	CurrentPrimaryInput = NewInput;
}

void UInputKeyBinding::RebindGamepadInput(const FInputChord& NewInput)
{
	// Check if it's not a gamepad key
	if (!IsInputAGamepadKey(NewInput))
	{
		SetSelectedGamepadInput(GamepadKeySelector);
		return;
	}

	if (bInitialized)// This is here to prevent a crash when pre-constructing
	{
		// Check if it's a duplicate key with any other bound gamepad key
		if (ControlsMenu->IsGamepadInputKeyDuplicate(this, NewInput))
		{
			SetSelectedGamepadInput(GamepadKeySelector);
			return;
		}
	}

	ControlsMenu->RebindInputMapping(this, CurrentGamepadInput, NewInput);
			
	CurrentGamepadInput = NewInput;
}

FInputChord UInputKeyBinding::GetSelectedPrimaryKey() const
{
	return PrimaryKeySelector->SelectedKey;
}

bool UInputKeyBinding::IsInputAGamepadKey(const FInputChord& NewInput)
{
	TArray<FKey> AllKeys;
	TArray<FKey> GamepadKeys;

	// Get all gamepad keys
	EKeys::GetAllKeys(AllKeys);
	for (const auto& Key : AllKeys)
	{
		const FName KeyName = Key.GetFName();

		if (KeyName.ToString().Contains("Gamepad"))
			GamepadKeys.Add(Key);
	}

	// Check if the new input is in fact a gamepad key
	for (const auto& GamepadKey : GamepadKeys)
	{
		if (NewInput.Key == GamepadKey)
		{
			return true;
		}
	}

	return false;
}
