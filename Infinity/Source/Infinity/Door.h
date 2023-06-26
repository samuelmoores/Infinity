// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interactable.h"
#include "Door.generated.h"

/**
 * 
 */
UCLASS()
class INFINITY_API ADoor : public AInteractable
{
	GENERATED_BODY()

	bool isOpen;
	bool opening;
	bool isClosed;
	bool closing;
	FVector OpenLocation;
	FVector ClosedLocation;
	FVector CurrentLocation;

	float timeElapsed;
	float deltaTime;
	float InterpSpeed;

	FTimerHandle TimerHandle;

	void Door();


	void BeginPlay() override;

public:
	UFUNCTION(BlueprintCallable)
	void Open();

	FString num;
	
	void MoveDoor();


};

