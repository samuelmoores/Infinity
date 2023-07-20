// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Scanner.generated.h"

UCLASS()
class INFINITY_API AScanner : public AActor
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly)
	class UBoxComponent* BoxCollider;

	UPROPERTY(EditDefaultsOnly)
	UStaticMeshComponent* Mesh;

	/**Scanner must check if player has keycard to open door*/
	class AInfinityCharacter* Player;

	/**Scanner must be able to open the doors it's connected to*/
	TArray<AActor*> Doors;
	class ADoor* Door;
	bool activated;
	
public:	
	// Sets default values for this actor's properties
	AScanner();
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//Overlap event overrides
	void NotifyActorBeginOverlap(AActor* OtherActor) override;
	void NotifyActorEndOverlap(AActor* OtherActor) override;

	//Changes screen material when overlapped with player
	void UpdateScreen(AActor* OtherActor, int materialIndex);

	//References the closest door and calls it's open function
	void OpenDoor();

	//returns true if overlapping player
	UFUNCTION(BlueprintCallable)
	bool CheckActivation();

};
