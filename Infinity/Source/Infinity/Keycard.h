// Fill out your copyright notice in the Description page of Project Settings.
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "KeyCard.generated.h"
UCLASS()
class INFINITY_API AKeyCard : public AActor
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly)
	class UBoxComponent* BoxCollider;

	UPROPERTY(EditDefaultsOnly)
	UStaticMeshComponent* Mesh;

	class AInfinityCharacter* Player;

	UPROPERTY(EditAnywhere)
	float rotationSpeed;
	
	float rotation;
	bool playerOverlapping;
	
public:	
	// Sets default values for this actor's properties
	AKeyCard();

protected:
	void NotifyActorBeginOverlap(AActor* OtherActor) override;
	void NotifyActorEndOverlap(AActor* OtherActor) override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};

