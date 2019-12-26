// Copyright Ali El Saleh 2019

#include "MenuBase.h"
#include "MenuHUD.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/GameUserSettings.h"
#include "Engine/Engine.h"
#include "TimerManager.h"
#include "WidgetTree.h"
#include "MenuSetting.h"
#include "WidgetAnimation.h"
#include "Buttons/MenuButtonWidget.h"

void UMenuBase::Init()
{
	MenuHUD = Cast<AMenuHUD>(UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetHUD());
	GEngine->GetGameUserSettings()->LoadSettings(true);

	//if (!Animation)
	//	UDebug::LogDebugMessage(ERROR, FString(GetName() + " | Fade anim is null. You forgot to assign the fade animation in widget blueprint"), true);
}

void UMenuBase::InitializeSettings()
{
	for (auto Setting : MenuSettings)
	{
		Setting->SetMenuReference(this);
		Setting->Init();
		//ULog::LogDebugMessage(INFO, FString(Setting->GetName() + " initialized"), true);
	}
}

void UMenuBase::AddSetting(UMenuSetting* Setting)
{
	MenuSettings.Add(Setting);
}

bool UMenuBase::OnButtonHovered_Implementation(UMenuButtonWidget* Button)
{
	Button->OnButtonHovered();
	MenuTooltipText = Button->GetButtonTooltip();

	if (bCanPlayHoverSound)
		UGameplayStatics::PlaySound2D(this, Button->HoveredSound);

	return true;
}

bool UMenuBase::OnButtonUnhovered_Implementation(UMenuButtonWidget* Button)
{
	Button->OnButtonUnhovered();
	MenuTooltipText = FText::AsCultureInvariant("");

	return true;
}

void UMenuBase::StoreAllSettings(UPanelWidget* ParentWidget)
{
	for (int32 i = 0; i < ParentWidget->GetChildrenCount(); i++)
	{
		const auto Setting = ParentWidget->GetChildAt(i);
		
		if (Setting->IsA(UMenuSetting::StaticClass()))
			AddSetting(Cast<UMenuSetting>(Setting));
		else
		{
			// Recursively check every panel widget
			// We need to check the children of panel widgets as well, we should not discard them because they could contain child widgets
			if (Setting->IsA(UPanelWidget::StaticClass()))
			{
				const auto PanelWidget = Cast<UPanelWidget>(Setting);

				StoreAllSettings(PanelWidget);
			}
		}
	}
}

void UMenuBase::FadeIn()
{
	if (Animation)
		PlayAnimation(Animation, 0.0f, 1, EUMGSequencePlayMode::Reverse);
}

void UMenuBase::FadeOut()
{
	if (Animation)
		PlayAnimation(Animation);
}

void UMenuBase::OnAnimationStarted_Implementation(const UWidgetAnimation* Animation)
{
	SetVisibility(ESlateVisibility::Visible);
}

void UMenuBase::OnAnimationFinished_Implementation(const UWidgetAnimation* Animation)
{
	if (RenderOpacity <= 0.0f)
		SetVisibility(ESlateVisibility::Hidden);
}

FReply UMenuBase::NativeOnKeyUp(const FGeometry& InGeometry, const FKeyEvent& InKeyEvent)
{
	Super::NativeOnKeyUp(InGeometry, InKeyEvent);

	if (InKeyEvent.GetKey() == EKeys::Gamepad_FaceButton_Right)
	{
		OnGamepadBackButtonPressed();
	}

	return FReply::Handled();
}

void UMenuBase::Apply()
{
	for (auto MenuSetting : MenuSettings)
	{
		MenuSetting->Apply();
	}

	GEngine->GetGameUserSettings()->ApplySettings(false);
	GEngine->GetGameUserSettings()->SaveConfig();
}

void UMenuBase::GoForward()
{
	GetWorld()->GetTimerManager().ClearTimer(ForwardTimerHandle);
}

void UMenuBase::Back()
{
	if (Animation)
		GetWorld()->GetTimerManager().SetTimer(BackTimerHandle, this, &UMenuBase::GoBack, 1.0f, false, Animation->GetEndTime());
	else
		GoBack();
}

void UMenuBase::Reset()
{
	for (auto Setting : MenuSettings)
	{
		if (Setting->IsAffectedByReset())
			Setting->Reset();
	}

	Apply();
}

void UMenuBase::GoBack()
{
	GetWorld()->GetTimerManager().ClearTimer(BackTimerHandle);
}

bool UMenuBase::AreAllSettingsDefault()
{
	int32 Changes = 0;

	// Go through each setting in this menu
	for (auto Setting : MenuSettings)
	{
		// Add settings that have been changed and can be reset
		if (!Setting->IsDefault() && Setting->IsAffectedByReset())
		{
			//ULog::DebugMessage(INFO, Setting->GetName() + " is not default", true);
			Changes++;
		}
	}

	return Changes == 0;
}

void UMenuBase::SetMenuTooltipText(const FText& Text)
{
	MenuTooltipText = Text;
}

