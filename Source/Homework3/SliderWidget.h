// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SliderWidget.generated.h"


class UProgressBar;
class UTextBlock;
/**
 * 
 */
UCLASS()
class HOMEWORK3_API USliderWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	UFUNCTION(Category = "Bullet")
	void BulletMinus();

protected:
	virtual void NativeConstruct() override;


public:
	UPROPERTY(EditAnywhere, Category = "Bullet")
	float MaxBullet;

	float CurrentBullet;

protected:

	UPROPERTY(EditAnywhere, Category = "Sliders", meta = (BindWidget))
	TObjectPtr<UProgressBar> WeaponBar;

	UPROPERTY(EditAnywhere, Category = "Sliders", meta = (BindWidget))
	TObjectPtr<UProgressBar> HealthBar;
	
	UPROPERTY(EditAnywhere, Category = "Sliders", meta = (BindWidget))
	TObjectPtr<UTextBlock> WeaponText;
	
};
