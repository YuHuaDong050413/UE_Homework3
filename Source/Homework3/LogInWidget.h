// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "LogInWidget.generated.h"

//class FMath;
class AHomework3Character;
class UProgressBar;
class UCanvasPanel;
class UEditableTextBox;
class UButton;
class UImage;
class UTextBlock;
/**
 * 
 */
UCLASS()
class HOMEWORK3_API ULogInWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeConstruct() override;

	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

	UFUNCTION(Category = "LogIn")
	virtual void OnTextChanged(const FText& Text);

	UFUNCTION(Category = "LogIn")
	void OnButtonClicked();

	UFUNCTION(Category = "LogIn")
	void Loading();

public:
	UPROPERTY(EditAnywhere, Category = "LogIn", meta = (BindWidget))
	TObjectPtr<UButton> ConfirmButton;

protected:
	FString Password;
	FTimerHandle LoadingTimer;
	bool bIsLoaded = false;
	float LoadingBarPersent = 0.0f;
	
protected:
	UPROPERTY(EditAnywhere, Category = "LogIn", meta = (BindWidget))
	TObjectPtr<UCanvasPanel> LogInCanvas;

	UPROPERTY(EditAnywhere, Category = "LogIn", meta = (BindWidget))
	TObjectPtr<UCanvasPanel> LoadCanvas;

	UPROPERTY(EditAnywhere, Category = "LogIn", meta = (BindWidget))
	TObjectPtr<UEditableTextBox> InputName;

	UPROPERTY(EditAnywhere, Category = "LogIn", meta = (BindWidget))
	TObjectPtr<UEditableTextBox> InputPassword;

	UPROPERTY(EditAnywhere, Category = "LogIn", meta = (BindWidget))
	TObjectPtr<UImage> BackgroundCover;

	UPROPERTY(EditAnywhere, Category = "LogIn", meta = (BindWidget))
	TObjectPtr<UImage> BackgroundImage;

	UPROPERTY(EditAnywhere, Category = "LogIn", meta = (BindWidget))
	TObjectPtr<UImage> UserNameBackgroundImage;

	UPROPERTY(EditAnywhere, Category = "LogIn", meta = (BindWidget))
	TObjectPtr<UImage> PasswordBackgroundImage;

	UPROPERTY(EditAnywhere, Category = "LogIn", meta = (BindWidget))
	TObjectPtr<UImage> TitleBackgroundImage;
	
	UPROPERTY(EditAnywhere, Category = "LogIn", meta = (BindWidget))
	TObjectPtr<UTextBlock> ConfirmText;

	UPROPERTY(EditAnywhere, Category = "LogIn", meta = (BindWidget))
	TObjectPtr<UTextBlock> TitleText;

	UPROPERTY(EditAnywhere, Category = "LogIn", meta = (BindWidget))
	TObjectPtr<UTextBlock> UserNameText;

	UPROPERTY(EditAnywhere, Category = "LogIn", meta = (BindWidget))
	TObjectPtr<UTextBlock> PasswordText;

	UPROPERTY(EditAnywhere, Category = "LogIn", meta = (BindWidget))
	TObjectPtr<UProgressBar> LoadingBar;

	

};
