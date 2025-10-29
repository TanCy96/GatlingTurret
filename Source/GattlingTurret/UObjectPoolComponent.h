// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "UObjectPoolComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GATTLINGTURRET_API UObjectPoolComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UObjectPoolComponent();

	UFUNCTION(BlueprintCallable, Category="Object Pool")
	void InitializePool(TSubclassOf<AActor> ObjectClass, int32 InitialSize);

	UFUNCTION(BlueprintCallable, Category="Object Pool")
	AActor* GetPooledObject();

	UFUNCTION(BlueprintCallable, Category="Object Pool")
	void ReturnToPool(AActor* PooledActor);

protected:
	UPROPERTY()
	TArray<AActor*> Pool;

	UPROPERTY()
	TSubclassOf<AActor> PooledClass;
};
