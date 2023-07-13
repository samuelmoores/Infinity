// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Door.generated.h"

UCLASS()
class INFINITY_API ADoor : public AActor
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
	void Open();
	void Move();
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	void NotifyActorBeginOverlap(AActor* OtherActor) override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
