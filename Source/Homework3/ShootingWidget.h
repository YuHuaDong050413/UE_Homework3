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

protected:


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
public:

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
