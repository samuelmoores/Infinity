// Fill out your copyright notice in the Description page of Project Settings.


#include "Scanner.h"

#include "Door.h"
#include "InfinityCharacter.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AScanner::AScanner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AScanner::BeginPlay()
{
	Super::BeginPlay();

}

void AScanner::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}

void AScanner::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);
	
	//Check if player has keycard
	if(Player)
	{
		if(Player->GetHasKeycard())
		{
			UpdateScreen(OtherActor, 6);
		}
		else
		{
			UpdateScreen(OtherActor, 5);
		}
	}
	
	//Get all the doors
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ADoor::StaticClass(), Doors);

	//Get first distance between scanner and door
	float leastDistance = FVector::Dist(GetActorLocation(), Doors[0]->GetActorLocation());

	//Iterate through all the doors to get all the distances
	for(int i = 0; i < Doors.Num(); i++)
	{
		//save each distance
		float currDistance = FVector::Dist(GetActorLocation(), Doors[i]->GetActorLocation());

		//check if it's the smallest distance or the same as the first distance found
		if(currDistance <= leastDistance)
		{
			Door = Cast<ADoor>(Doors[i]);
			leastDistance = currDistance;
		}
	}
	
}

void AScanner::NotifyActorEndOverlap(AActor* OtherActor)
{
	Super::NotifyActorEndOverlap(OtherActor);
	UpdateScreen(OtherActor, 4);

}

void AScanner::UpdateScreen(AActor* OtherActor, int materialIndex)
{
	if(OtherActor->ActorHasTag("Player"))
	{
		//Set screen index[0] to new material
		Mesh->SetMaterial(0, Mesh->GetMaterial(materialIndex));
	}
}

void AScanner::OpenDoor()
{
	if(Door)
		Door->Open();
}


