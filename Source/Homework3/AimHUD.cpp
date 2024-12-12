// Fill out your copyright notice in the Description page of Project Settings.

#include "AimHUD.h"
#include "Components/Image.h"


void AAimHUD::BeginPlay()
{
	Super::BeginPlay();
	PrimaryActorTick.bCanEverTick = true;

	if (ShootingWidgetClass)
	{
		ShootingWidgetInstance = CreateWidget<UShootingWidget>(GetWorld(), ShootingWidgetClass);

	}

	if (LogInWidgetClass)
	{
		LogInWidgetInstance = CreateWidget<ULogInWidget>(GetWorld(), LogInWidgetClass);
		if (LogInWidgetInstance)
		{
			LogInWidgetInstance->AddToViewport();
		}
	}

	if (SliderWidgetClass)
	{
		SliderWidgetInstance = CreateWidget<USliderWidget>(GetWorld(), SliderWidgetClass);
	}
}

void AAimHUD::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (ShootingWidgetInstance && SliderWidgetInstance && !LogInWidgetInstance->IsVisible() && AimHUDInstance == nullptr)
	{
		ShootingWidgetInstance->LeftUpImage->SetVisibility(ESlateVisibility::Hidden);
		ShootingWidgetInstance->RightUpImage->SetVisibility(ESlateVisibility::Hidden);
		ShootingWidgetInstance->LeftDownImage->SetVisibility(ESlateVisibility::Hidden);
		ShootingWidgetInstance->RightDownImage->SetVisibility(ESlateVisibility::Hidden);
		ShootingWidgetInstance->AddToViewport();
		SliderWidgetInstance->AddToViewport();
		AimHUDInstance = this;
	}

}

