// Fill out your copyright notice in the Description page of Project Settings.


#include "Interactable.h"

// Sets default values
AInteractable::AInteractable()
{
	canInteract = false;
}

void AInteractable::NotifyActorBeginOverlap(AActor* OtherActor)
{
	if(OtherActor->ActorHasTag("Player"))
		canInteract = true;
}

void AInteractable::NotifyActorEndOverlap(AActor* OtherActor)
{
	if(OtherActor->ActorHasTag("Player"))
		canInteract = false;
}

