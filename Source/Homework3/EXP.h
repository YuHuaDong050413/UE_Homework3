// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EXP.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnHitTargetDelegate);

class UBoxComponent;
class URotatingMovementComponent;
class UShootingWidget;

UCLASS()
class HOMEWORK3_API AEXP : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEXP();

	UPROPERTY(BlueprintAssignable, Category = "EXP")
	FOnHitTargetDelegate OnHitTarget;

	UFUNCTION()
	void OnBeginOverlapEvent(
		UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

protected:
	UPROPERTY(EditAnywhere, Category = "EXP")
	TObjectPtr<UStaticMeshComponent> MeshComponent;

	UPROPERTY(EditAnywhere, Category = "EXp")
	TObjectPtr<UBoxComponent> BoxCollider;

	UPROPERTY(EditAnywhere, Category = "EXP")
	TObjectPtr<URotatingMovementComponent> RotatingComponent;

	UPROPERTY(EditAnywhere, Category = "EXP")
	TSubclassOf<UShootingWidget> ShootingWidgetClass;

	UPROPERTY()
	TObjectPtr<UShootingWidget> ShootingWidgetInstance;

	
};
