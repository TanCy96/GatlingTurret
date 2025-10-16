// Fill out your copyright notice in the Description page of Project Settings.


#include "GatlingGun.h"
#include "Components/SceneComponent.h"
#include "Engine/World.h"

// Sets default values
AGatlingGun::AGatlingGun()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned
void AGatlingGun::BeginPlay()
{
	Super::BeginPlay();
	// Initialize to current relative rotations
	if (RotatePivot)
	{
		CurrentYaw = RotatePivot->GetRelativeRotation().Yaw;
		CurrentPitch = RotatePivot->GetRelativeRotation().Pitch;
	}
}

void AGatlingGun::Aim(float YawInput, float PitchInput)
{
	if (!YawInput || !PitchInput) return;
	const float Delta = GetWorld()->GetDeltaSeconds();

	CurrentYaw += YawInput * AimSpeed * Delta;
	CurrentPitch += PitchInput * AimSpeed * Delta;

	CurrentYaw = FMath::Clamp(CurrentYaw, MinYaw, MaxYaw);
	CurrentPitch = FMath::Clamp(CurrentPitch, MinPitch, MaxPitch);

	RotatePivot->SetRelativeRotation(FRotator(CurrentPitch, CurrentYaw, 0));
}

