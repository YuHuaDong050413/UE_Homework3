// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "ShootingWidget.h"
#include "LogInWidget.h"
#include "SliderWidget.h"

#include "AimHUD.generated.h"

/**
 * 
 */
UCLASS()
class HOMEWORK3_API AAimHUD : public AHUD
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

protected:
	AAimHUD* AimHUDInstance = nullptr;

	UPROPERTY(EditAnywhere, Category = "EXP");
	TSubclassOf<UShootingWidget> ShootingWidgetClass;

	UPROPERTY(EditAnywhere, Category = "EXP")
	TSubclassOf<ULogInWidget> LogInWidgetClass;

	UPROPERTY(EditAnywhere, Category = "EXP")
	TSubclassOf<USliderWidget> SliderWidgetClass;

public:
	UPROPERTY()
	TObjectPtr<UShootingWidget> ShootingWidgetInstance;

	UPROPERTY()
	TObjectPtr<ULogInWidget> LogInWidgetInstance;

	UPROPERTY()
	TObjectPtr<USliderWidget> SliderWidgetInstance;
	
};
