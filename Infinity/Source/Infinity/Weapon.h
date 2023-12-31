// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interactable.h"
#include "Weapon.generated.h"

UCLASS()
class INFINITY_API AWeapon : public AInteractable
{
	GENERATED_BODY()

public:	
	// Sets default values for this actor's properties
	AWeapon();

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;

	//Handles attachments to the player
	void AttachToPlayer(AInfinityCharacter* AttachPlayerCharacter, AWeapon* Weapon);
	void DetachFromPlayer();

};
