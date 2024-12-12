// Fill out your copyright notice in the Description page of Project Settings.


#include "EXP.h"

#include "GameFramework/RotatingMovementComponent.h"
#include "ShootingWidget.h"
#include "Components/BoxComponent.h"
#include "Components/Image.h"


// Sets default values
AEXP::AEXP()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	BoxCollider = CreateDefaultSubobject<UBoxComponent>(FName("BoxCollider"));
	SetRootComponent(BoxCollider);
	BoxCollider->SetGenerateOverlapEvents(true);
	BoxCollider->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	BoxCollider->SetCollisionResponseToAllChannels(ECR_Ignore);
	BoxCollider->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);

	FScriptDelegate delegate;
	delegate.BindUFunction(this, FName("OnBeginOverlapEvent"));
	BoxCollider->OnComponentBeginOverlap.AddUnique(delegate);

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(FName("MeshComponent"));
	MeshComponent->SetupAttachment(BoxCollider);
	MeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	MeshComponent->SetCollisionResponseToAllChannels(ECR_Ignore);
	MeshComponent->SetGenerateOverlapEvents(false);

	RotatingComponent = CreateDefaultSubobject<URotatingMovementComponent>(FName("RotatingComponent"));

}


void AEXP::OnBeginOverlapEvent(
	UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Log, TEXT("%s"), *OtherActor->GetName());
	if (ShootingWidgetClass)
	{
		ShootingWidgetInstance = CreateWidget<UShootingWidget>(GetWorld(), ShootingWidgetClass);
		if (ShootingWidgetInstance)
		{
			if (ShootingWidgetInstance->LeftUpImage->GetVisibility() == ESlateVisibility::Hidden)
			{
				ShootingWidgetInstance ->LeftUpImage->SetVisibility(ESlateVisibility::Visible);
				ShootingWidgetInstance ->RightUpImage->SetVisibility(ESlateVisibility::Visible);
				ShootingWidgetInstance ->LeftDownImage->SetVisibility(ESlateVisibility::Visible);
				ShootingWidgetInstance ->RightDownImage->SetVisibility(ESlateVisibility::Visible);

			}

			ShootingWidgetInstance->AddToViewport();
			ShootingWidgetInstance->PlayOnTargetAnimation();
			UE_LOG(LogTemp, Log, TEXT("play animation"));
		}
	}
	Destroy();
}