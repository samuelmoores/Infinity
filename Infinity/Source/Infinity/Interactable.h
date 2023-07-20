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

protected:
	class AInfinityCharacter* Player;
	
public:	
	// Sets default values for this actor's properties
	AInteractable();
	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
	virtual void NotifyActorEndOverlap(AActor* OtherActor) override;

	UFUNCTION(BlueprintCallable)
	FORCEINLINE bool GetCanInteract() const {return canInteract;}
	

};
