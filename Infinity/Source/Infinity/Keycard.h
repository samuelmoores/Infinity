// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "KeyCard.generated.h"

class UBoxComponent;
UCLASS()
class INFINITY_API AKeyCard : public AActor
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly)
	UBoxComponent* BoxCollider;

	UPROPERTY(EditDefaultsOnly)
	UStaticMeshComponent* Mesh;

	UPROPERTY(EditAnywhere)
	float rotationSpeed;
	
	float rotation;
	
public:	
	// Sets default values for this actor's properties
	AKeyCard();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
