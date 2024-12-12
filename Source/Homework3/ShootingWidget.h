// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ShootingWidget.generated.h"

class UTextBlock;
class UImage;
class UWidgetAnimation;
class UProgressBar;
/**
 * 
 */
UCLASS()
class HOMEWORK3_API UShootingWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable, Category = "Shooting")
	void PlayOnTargetAnimation();

	/*UFUNCTION(Category = "Shooting")
	void BulletMinus();*/

protected:
	//virtual void NativeConstruct() override;


protected:

	UPROPERTY(EditAnywhere, Category = "Shooting", meta = (BindWidget))
	TObjectPtr<UImage> leftImage;

	UPROPERTY(EditAnywhere, Category = "Shooting", meta = (BindWidget))
	TObjectPtr<UImage> RightImage;

	UPROPERTY(EditAnywhere, Category = "Shooting", meta = (BindWidget))
	TObjectPtr<UImage> UpImage;

	UPROPERTY(EditAnywhere, Category = "Shooting", meta = (BindWidget))
	TObjectPtr<UImage> DownImage;
	
	UPROPERTY(EditAnywhere, Category = "Shooting", meta = (BindWidget))
	TObjectPtr<UImage> Dolt;

	/*UPROPERTY(EditAnywhere, Category = "Shooting", meta = (BindWidget))
	TObjectPtr<UProgressBar> BloodBar;

	UPROPERTY(EditAnywhere, Category = "Shooting", meta = (BindWidget))
	TObjectPtr<UProgressBar> WeaponBar;

	UPROPERTY(EditAnywhere, Category = "Shooting", meta = (BindWidget))
	TObjectPtr<UTextBlock> WeaponText;*/
public:
	/*UPROPERTY()
	float CurrentBullet;

	UPROPERTY(EditAnywhere, Category = "Bullet")
	float MaxBullet;*/

	UPROPERTY(EditAnywhere, Category = "Shooting", meta = (BindWidget))
	TObjectPtr<UImage> LeftUpImage;

	UPROPERTY(EditAnywhere, Category = "Shooting", meta = (BindWidget))
	TObjectPtr<UImage> LeftDownImage;

	UPROPERTY(EditAnywhere, Category = "Shooting", meta = (BindWidget))
	TObjectPtr<UImage> RightUpImage;

	UPROPERTY(EditAnywhere, Category = "Shooting", meta = (BindWidget))
	TObjectPtr<UImage> RightDownImage;

	UPROPERTY(Transient, meta = (BindWidgetAnim))
	TObjectPtr<UWidgetAnimation> OnTargetAnimation;

	
};
