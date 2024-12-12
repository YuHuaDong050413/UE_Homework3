// Fill out your copyright notice in the Description page of Project Settings.

#include "ShootingWidget.h"
#include "Components/TextBlock.h"
#include "Components/ProgressBar.h"


//void UShootingWidget::NativeConstruct()
//{
//	Super::NativeConstruct();
//	UE_LOG(LogTemp, Warning, TEXT("NativeConstruct"));
//	CurrentBullet = MaxBullet;
//	UE_LOG(LogTemp, Warning, TEXT("CurrentBullet: %f"), CurrentBullet);
//	WeaponBar->SetPercent(CurrentBullet / MaxBullet);
//	UE_LOG(LogTemp, Warning, TEXT("Persent: %f"), CurrentBullet / MaxBullet);
//}


void UShootingWidget::PlayOnTargetAnimation()
{
	if (OnTargetAnimation)
	{
		PlayAnimation(OnTargetAnimation);
	}
}

//void UShootingWidget::BulletMinus()
//{
//	if (WeaponBar && WeaponText)
//	{
//		UE_LOG(LogTemp, Warning, TEXT("BulletMinus"));
//		CurrentBullet--;
//		UE_LOG(LogTemp, Warning, TEXT("CurrentBullet: %f"), CurrentBullet);
//		UE_LOG(LogTemp, Warning, TEXT("Persent: %f"), CurrentBullet / MaxBullet);
//
//		/*WeaponText->SetText(FText::Format(FText::AsNumber(CurrentBullet), 
//			FText::FromString(" / "), FText::AsNumber(MaxBullet)));*/
//		WeaponText->SetText(FText::FromString(FString::Printf(TEXT("%.0f/%.0f"), CurrentBullet, MaxBullet))); 
//		/*int32 CurrentBulletInt = FMath::FloorToInt(CurrentBullet); 
//		int32 MaxBulletInt = FMath::FloorToInt(MaxBullet); 
//		WeaponText->SetText(FText::FromString(FString::Printf(TEXT("%d/%d"), 
//			CurrentBulletInt, MaxBulletInt))); */
//		WeaponBar->SetPercent(CurrentBullet / MaxBullet);
//	}
//}


