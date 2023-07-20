// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interactable.generated.h"

UCLASS()
class INFINITY_API AInteractable : public AActor
{
	GENERATED_BODY()
	bool canInteract;
	
public:	
	// Sets default values for this actor's properties
	AInteractable();
	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
	virtual void NotifyActorEndOverlap(AActor* OtherActor) override;
	FORCEINLINE const bool* GetCanInteract(){return &canInteract;}
};
