// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interactable.h"
#include "Keycard.generated.h"

/**
 * 
 */
UCLASS()
class INFINITY_API AKeycard : public AInteractable
{
	GENERATED_BODY()
public:
	class APlayerCharacter* PlayerCharacter;

	FTimerHandle TimerHandle;

	AKeycard();

	void BeginPlay() override;

	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;
	void OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) override;

	void TakeCard();
	
};
