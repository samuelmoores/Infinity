// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Pistol.generated.h"

UCLASS()
class INFINITY_API APistol : public AActor
{
	GENERATED_BODY()

	//Pistol Mesh
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* Mesh;

	//Collider for overlap events
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UBoxComponent* BoxCollider;

	//Controls whether the mesh hovers up or down
	int offset;

	//Is the pistol connected to the player
	bool attachedToPlayer;


public:

	//Player reference for attachment
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	class AInfinityCharacter* PlayerCharacter;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UParticleSystemComponent* MuzzleFlashLocation;

	UParticleSystem* MuzzleFlash;

	FVector StartingLocationHover;
	FVector EndingLocationHover;
	float LerpDistance;
	float LerpSpeed;
	float rotation;
	float rotationSpeed;

	bool canPickup;
	
	// Sets default values for this actor's properties
	APistol();

	//Connects the pistol to the player
	void AttachToPlayer(AInfinityCharacter* AttachPlayerCharacter);
	void DetachFromPlayer();
	void HolsterPistol(AInfinityCharacter* AttachPlayerCharacter);

	//The pistol mesh floats up and down before being picked up
	void Hover(float DeltaTime);

	//Create muzzle flash
	void SpawnMuzzleFlash();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
	virtual void NotifyActorEndOverlap(AActor* OtherActor) override;
	
};


