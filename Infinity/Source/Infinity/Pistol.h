// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Weapon.h"
#include "InfinityCharacter.h"
#include "Pistol.generated.h"

UCLASS()
class INFINITY_API APistol : public AWeapon
{
	GENERATED_BODY()

	//Pistol Mesh
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* Mesh;

	//Collider for overlap events
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UBoxComponent* BoxCollider;

	//Muzzle flash reference from blueprint with exact location
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UParticleSystemComponent* MuzzleFlashLocation;

	//Patricle system to be spawned
	UParticleSystem* MuzzleFlash;
	
	/** Particle System for shot hit location*/
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Particles, meta = (AllowPrivateAccess = "true"))
	UParticleSystem* ShotHitParticles;

	//Lerp settings for pistol hover and rotation before being picked up
	FVector StartingLocationHover;
	FVector EndingLocationHover;
	float LerpDistance;
	float LerpSpeed;
	float rotation;
	float rotationSpeed;
	
	//Controls whether the mesh hovers up or down
	int offset;

	//Is the pistol connected to the player
	bool attachedToPlayer;

public:
	// Sets default values for this actor's properties
	APistol();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
	virtual void NotifyActorEndOverlap(AActor* OtherActor) override;
	
	//The pistol mesh floats up and down before being picked up
	void Hover(float DeltaTime);

	//Handles attachments to the player
	void AttachToPlayer(AInfinityCharacter* AttachPlayerCharacter);
	void DetachFromPlayer();
	void HolsterPistol(AInfinityCharacter* AttachPlayerCharacter);

	//Create muzzle flash
	void SpawnMuzzleFlash();

	//Shoot the gun using a Line Trace
	void Shoot(FVector StartLocation, FVector EndLocation);
	
	//Allows references to check if the pistol is currently overlapped and can be picked up
	bool canPickup;
	
};


