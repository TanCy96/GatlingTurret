// Fill out your copyright notice in the Description page of Project Settings.


#include "UObjectPoolComponent.h"
#include "Engine/World.h"

// Sets default values for this component's properties
UObjectPoolComponent::UObjectPoolComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;
}

void UObjectPoolComponent::InitializePool(TSubclassOf<AActor> ObjectClass, int32 InitialSize)
{
	PooledClass = ObjectClass;
	UWorld* World = GetWorld();
	if (!World || !*PooledClass) return;

	for (int32 i = 0; i < InitialSize; i++)
	{
		AActor* NewActor = World->SpawnActor<AActor>(PooledClass, FVector::ZeroVector, FRotator::ZeroRotator);
		if (!NewActor) continue;
		NewActor->SetActorEnableCollision(false);
		NewActor->SetActorHiddenInGame(true);
		Pool.Add(NewActor);
	}
}

AActor* UObjectPoolComponent::GetPooledObject()
{
	for (AActor* Actor : Pool)
	{
		if (!Actor->IsActorTickEnabled())
		{
			Actor->SetActorHiddenInGame(false);
			Actor->SetActorEnableCollision(true);
			Actor->SetActorTickEnabled(true);
			return Actor;
		}
	}

	if (*PooledClass)
	{
		AActor* NewActor = GetWorld()->SpawnActor<AActor>(PooledClass);
		Pool.Add(NewActor);
		return NewActor;
	}

	return nullptr;
}

void UObjectPoolComponent::ReturnToPool(AActor* PooledActor)
{
	if (!PooledActor) return;

	PooledActor->SetActorHiddenInGame(true);
	PooledActor->SetActorEnableCollision(false);
	PooledActor->SetActorTickEnabled(false);
}




