// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interactable.h"
#include "Computer.generated.h"

/**
 * 
 */
UCLASS()
class INFINITY_API AComputer : public AInteractable
{
	GENERATED_BODY()

	AComputer();

	UFUNCTION(BlueprintCallable)
	void TurnOnScreen();

	virtual void Tick(float DeltaSeconds) override;

	virtual void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;
	
};
