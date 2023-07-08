// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interactable.h"
#include "Scanner.generated.h"

/**
 * 
 */
UCLASS()
class INFINITY_API AScanner : public AInteractable
{
	GENERATED_BODY()

	FTimerHandle TimerHandle;

	void BeginPlay() override;

	class ADoor* Door;

public:

	UPROPERTY(BlueprintReadOnly)
	bool playerOverlapped;

	AScanner();

	UFUNCTION(BlueprintCallable)
	void TurnOnScreen(bool canEnter);

	void OpenDoor();

	virtual void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;
	virtual void OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) override;
};
