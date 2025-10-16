// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GatlingGun.generated.h"

UCLASS()
class GATTLINGTURRET_API AGatlingGun : public AActor
{
	GENERATED_BODY()
	
public:	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Turret")
	USceneComponent* RotatePivot;
	
	// Sets default values for this actor's properties
	AGatlingGun();

	// Callable from Blueprint to rotate the turret gun
	UFUNCTION(BlueprintCallable, Category="Turret")
	void Aim(float YawInput, float PitchInput);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category="Turret")
	float AimSpeed = 45.f;

	UPROPERTY(EditAnywhere, Category="Turret|Clamp")
	float MinYaw = -45.f;
	UPROPERTY(EditAnywhere, Category="Turret|Clamp")
	float MaxYaw = 45.f;
	UPROPERTY(EditAnywhere, Category="Turret|Clamp")
	float MinPitch = -10.f;
	UPROPERTY(EditAnywhere, Category="Turret|Clamp")
	float MaxPitch = 30.f;

private:
	float CurrentYaw = 0.f;
	float CurrentPitch = 0.f;

};
