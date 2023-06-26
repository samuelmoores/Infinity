// Fill out your copyright notice in the Description page of Project Settings.


#include "Door.h"

#include "PlayerCharacter.h"
#include "VectorTypes.h"
#include "Components/SphereComponent.h"
#include "Math/UnitConversion.h"

void ADoor::BeginPlay()
{
	Super::BeginPlay();

	isOpen = false;
	ClosedLocation = GetActorLocation();
	InterpSpeed = 1.0f;
	OpenLocation = GetActorLocation() + FVector(0.0, -290.0f, 0.0f);

	deltaTime = 0.0167;
	timeElapsed = 0.0f;


}

void ADoor::Door()
{
	Mesh->SetMobility(EComponentMobility::Movable);
	SphereCollider->SetupAttachment(RootComponent);

	num = "Eight";
}

void ADoor::Open()
{
	CurrentLocation = GetActorLocation();
	GetWorldTimerManager().SetTimer(TimerHandle, this, &ADoor::MoveDoor, GetWorld()->GetDeltaSeconds(), true);

}


void ADoor::MoveDoor()
{

	if(!isOpen)
	{
		timeElapsed += GetWorld()->GetDeltaSeconds();

		if(timeElapsed > 0.0 && timeElapsed < 3.0f)
		{
			FVector NewLocation = FMath::Lerp(ClosedLocation, OpenLocation, timeElapsed / 3.0f);
			Mesh->SetWorldLocation(NewLocation);
	
		}
		
		if(timeElapsed >= 6.0f)
		{
			timeElapsed = 0.0f;
			isOpen = true;
		}

	}
	else
	{
		timeElapsed += GetWorld()->GetDeltaSeconds();

		FVector NewLocation = FMath::Lerp(OpenLocation, ClosedLocation, timeElapsed / 3.0f);
		Mesh->SetWorldLocation(NewLocation);

		if(timeElapsed >= 3.0f)
		{
			GetWorldTimerManager().ClearTimer(TimerHandle);
			timeElapsed = 0.0f;
			isOpen = false;
		}

	}
	
	
}









