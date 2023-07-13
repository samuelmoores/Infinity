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
	class TArray<AActor*> Doors;
	class ADoor* FrontDoor;
	bool activated;
	
public:	
	// Sets default values for this actor's properties
	AScanner();
	void UpdateScreen(AActor* OtherActor, int materialIndex);
	void OpenDoor();
	UFUNCTION(BlueprintCallable)
	bool CheckActivation();
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	void NotifyActorBeginOverlap(AActor* OtherActor) override;
	void NotifyActorEndOverlap(AActor* OtherActor) override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
