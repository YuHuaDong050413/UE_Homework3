// Fill out your copyright notice in the Description page of Project Settings.

#include "Homework3Character.h"
#include "Components/Button.h"
#include "Components/EditableTextBox.h"
#include "Components/ProgressBar.h"
#include "Components/CanvasPanel.h"
#include "LogInWidget.h"

void ULogInWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (ConfirmButton && InputName && InputPassword)
	{
		ConfirmButton->OnClicked.AddDynamic(this, &ULogInWidget::OnButtonClicked);
	}

	if (InputPassword)
	{
		InputPassword->OnTextChanged.AddDynamic(this, &ULogInWidget::OnTextChanged);
	}

}

void ULogInWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);
	UE_LOG(LogTemp, Warning, TEXT("LogInWidget tick is working"));
	if (LoadingBar && LoadCanvas->IsVisible() && !bIsLoaded)
	{
		UE_LOG(LogTemp, Log, TEXT("LoadCanvas is visible"));
		GetWorld()->GetTimerManager().SetTimer(LoadingTimer, this, &ULogInWidget::Loading, 1.0f, true);
		bIsLoaded = true;
	}
}

void ULogInWidget::OnButtonClicked()
{
	if (!InputName->GetText().IsEmpty() && !InputPassword->GetText().IsEmpty())
	{
		//this->SetVisibility(ESlateVisibility::Hidden);
		this->LogInCanvas->SetVisibility(ESlateVisibility::Hidden);
		this->LoadCanvas->SetVisibility(ESlateVisibility::Visible);
	}
}

void ULogInWidget::OnTextChanged(const FText& Text)
{
	UE_LOG(LogTemp, Log, TEXT("Text changed: %s"), *Text.ToString());
	if (InputPassword)
	{
		Password += TEXT("*");
		InputPassword->SetText(FText::FromString(Password));
	}
}

void ULogInWidget::Loading()
{
	UE_LOG(LogTemp, Log, TEXT("Loading..."));
	float value = FMath::FRandRange(0.0f, 0.4f);
	if (LoadingBarPersent < 1.0f)
	{
		LoadingBarPersent += value;
		LoadingBar->SetPercent(LoadingBarPersent);
	}
	else
	{
		this->SetVisibility(ESlateVisibility::Hidden);
	}
}


