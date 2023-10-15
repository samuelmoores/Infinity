// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interactable.generated.h"

UCLASS()
class INFINITY_API AInteractable : public AActor
{
	GENERATED_BODY()
	
	//Is the interactable overlapping the player?
	bool canInteract;
	
public:	
	// Sets default values for this actor's properties
	AInteractable();
	
protected:
	virtual void BeginPlay() override;

	//Player reference
	class AInfinityCharacter* Player;

	//Mesh
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* Mesh;

	//Collider for overlap events
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UBoxComponent* BoxCollider;

	//Lerp settings for hover and rotation before being picked up
	FVector StartingLocationHover;
	FVector EndingLocationHover;
	float LerpDistance;
	float LerpSpeed;
	float rotation;
	float rotationSpeed;
	
	//Controls whether the mesh hovers up or down
	int offset;

public:
	virtual void Tick(float DeltaSeconds) override;
	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
	virtual void NotifyActorEndOverlap(AActor* OtherActor) override;

	UFUNCTION(BlueprintCallable)
	FORCEINLINE bool GetCanInteract() const {return canInteract;}
	
	//The pistol mesh floats up and down before being picked up
	virtual void Hover(float DeltaTime);
	
	//Is the pistol connected to the player
	UPROPERTY(BlueprintReadOnly)
	bool attachedToPlayer;
	
};
