// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interactable.h"
#include "Scanner.generated.h"

UCLASS()
class INFINITY_API AScanner : public AInteractable
{
	GENERATED_BODY()

	/**Scanner must be able to open the doors it's connected to*/
	TArray<AActor*> Doors;
	class ADoor* Door;
	//bool activated;
	
public:	
	// Sets default values for this actor's properties
	AScanner();
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;

	//Overlap event overrides
	void NotifyActorBeginOverlap(AActor* OtherActor) override;
	void NotifyActorEndOverlap(AActor* OtherActor) override;

	//Changes screen material when overlapped with player
	void UpdateScreen(AActor* OtherActor, int materialIndex);

	//References the closest door and calls it's open function
	void OpenDoor();

	//returns true if overlapping player
	//UFUNCTION(BlueprintCallable)
	//bool CheckActivation();

};
