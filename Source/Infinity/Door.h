// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interactable.h"
#include "Door.generated.h"

UCLASS()
class INFINITY_API ADoor : public AInteractable
{
	GENERATED_BODY()
	
	//Is the door open or closed
	bool isOpen;

	//Settings for moving the door including locations, speed and time
	FVector openLocation;
	FVector closedLocation;
	FTimerHandle Timer;
	float openSpeed;
	float openTime;
	float openTimeLimit;
	float startTime;

public:	
	// Sets default values for this actor's properties
	ADoor();

	void BeginPlay() override;

	//Overlap overrides
	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;

	//Sets timer and calls Move()
	void Open();

	//Lerp from closed to open and back to closed
	void Move();

};
