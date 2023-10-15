// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InfinityCharacter.h"
#include "Weapon.h"
#include "Gun.generated.h"

/**
 * 
 */
UCLASS()
class INFINITY_API AGun : public AWeapon
{
	GENERATED_BODY()

	//Muzzle flash reference from blueprint with exact location
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UParticleSystemComponent* MuzzleFlashLocation;

	//Particle system to be spawned
	UParticleSystem* MuzzleFlash;
	
	/** Particle System for shot hit location*/
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Particles, meta = (AllowPrivateAccess = "true"))
	UParticleSystem* HitParticles;

public:
	// Sets default values for this actor's properties
	AGun();

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;

	void UnequipGun(AInfinityCharacter* AttachPlayerCharacter);

	//Shoot the gun using a Line Trace
	void Shoot(FVector StartLocation, FVector EndLocation);
	
	//Create muzzle flash
	void SpawnMuzzleFlash();
	
};
