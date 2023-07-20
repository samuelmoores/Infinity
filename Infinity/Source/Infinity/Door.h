// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interactable.h"
#include "Door.generated.h"

UCLASS()
class INFINITY_API ADoor : public AInteractable
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly)
	class UBoxComponent* BoxCollider;

	UPROPERTY(EditDefaultsOnly)
	UStaticMeshComponent* Mesh;

	float openSpeed;
	float openTime;
	float openTimeLimit;
	float startTime;
	FVector openLocation;
	FVector closedLocation;
	FTimerHandle Timer;
	bool isOpen;
	
public:	
	// Sets default values for this actor's properties
	ADoor();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//Overlap overrides
	void NotifyActorBeginOverlap(AActor* OtherActor) override;

	//Sets timer and calls Move()
	void Open();

	//Lerp from closed to open and back to closed
	void Move();

};
