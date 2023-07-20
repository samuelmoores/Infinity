// Fill out your copyright notice in the Description page of Project Settings.


#include "Door.h"

// Sets default values
ADoor::ADoor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(RootComponent);
	openSpeed = 50.0f;
	openTime = 0.0f;
	openTimeLimit = 4.0f;
	isOpen = false;
}

void ADoor::BeginPlay()
{
	Super::BeginPlay();
	openLocation = Mesh->GetComponentLocation() + FVector(0,-300.0f, 0);
	closedLocation = Mesh->GetComponentLocation();
}

void ADoor::Open()
{
	if(!isOpen)
	{
		startTime = GetWorld()->GetTimeSeconds();
		GetWorldTimerManager().SetTimer(Timer, this, &ADoor::Move, GetWorld()->GetDeltaSeconds()/openSpeed, true);
	}
}
void ADoor::Move()
{
	float elapsedTime = GetWorld()->GetTimeSeconds() - startTime;
	if(elapsedTime < 1.0f)
	{
		isOpen = true;
		float Alpha = FMath::Clamp(elapsedTime, 0.0f, 1.0f);
		Mesh->SetWorldLocation(FMath::Lerp(closedLocation, openLocation, Alpha));

	}
	else if(elapsedTime > 2.0f && elapsedTime < 3.0f)
	{
		float Alpha = FMath::Clamp(elapsedTime - 2.0f, 0.0f, 1.0f);
		Mesh->SetWorldLocation(FMath::Lerp(openLocation, closedLocation, Alpha));

	}else if(elapsedTime > 3.0f)
	{
		isOpen = false;
		GetWorldTimerManager().ClearTimer(Timer);
	}
}
void ADoor::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);
	if(GetCanInteract())
		Open();
}


