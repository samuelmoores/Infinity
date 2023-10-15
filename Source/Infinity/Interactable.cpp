// Fill out your copyright notice in the Description page of Project Settings.


#include "Interactable.h"
#include "InfinityCharacter.h"
#include "Components/BoxComponent.h"

// Sets default values
AInteractable::AInteractable()
{
	PrimaryActorTick.bCanEverTick = true;

	//Setup Pistol MEsh for Blueprint
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(RootComponent);

	//Attach Box Collider to Pistol Mesh
	BoxCollider = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollider"));
	BoxCollider->SetupAttachment((Mesh));
	canInteract = false;
	
	//Settings that allow pistol to hover and rotate in the level before being picked up
	LerpDistance = 30.0f;
	LerpSpeed = 50.0f;
	rotation = 0.0f;
	rotationSpeed = 75.0f;
}


void AInteractable::BeginPlay()
{
	Super::BeginPlay();
	
	if(GetWorld())
	{
		StartingLocationHover = GetActorLocation();
		EndingLocationHover = GetActorLocation() + FVector(0.0f, 0.0f, LerpDistance);
	}
	
}

void AInteractable::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

}

void AInteractable::NotifyActorBeginOverlap(AActor* OtherActor)
{
	if(OtherActor->ActorHasTag("Player"))
	{
		canInteract = true;
		Player = Cast<AInfinityCharacter>(OtherActor);	
	}
		
}

void AInteractable::NotifyActorEndOverlap(AActor* OtherActor)
{
	if(OtherActor->ActorHasTag("Player"))
	{
		canInteract = false;
		Player = nullptr;		
	}
}

void AInteractable::Hover(float DeltaTime)
{
	if(!attachedToPlayer)
	{
		float Alpha = FMath::Clamp(DeltaTime, 0.0f, 1.0f);
		//Linear Interpolate up and down at a rate of 100
		FVector NewLocation = FMath::Lerp(GetActorLocation(), GetActorLocation() + FVector(0.0f, 0.0f, LerpSpeed * offset), Alpha);
		Mesh->SetWorldLocation(NewLocation);
		if(NewLocation.Z >= EndingLocationHover.Z)
		{
			offset = -1;
		}else if(NewLocation.Z <= StartingLocationHover.Z)
		{
			offset = 1;
		}
		rotation +=DeltaTime;
		Mesh->SetRelativeRotation(FRotator(0.0f, rotation * rotationSpeed, 0.0f));
	}
}

