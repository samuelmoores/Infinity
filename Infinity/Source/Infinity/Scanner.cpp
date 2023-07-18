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
	PrimaryActorTick.bCanEverTick = false;

	BoxCollider = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollider"));
	BoxCollider->SetupAttachment(RootComponent);

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(BoxCollider);

	activated = false;
}

// Called when the game starts or when spawned
void AScanner::BeginPlay()
{
	Super::BeginPlay();

	
}

void AScanner::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);
	Player = Cast<AInfinityCharacter>(OtherActor);
	if(Player)
	{
		if(Player->hasKeycard)
			UpdateScreen(OtherActor, 6);
		else
			UpdateScreen(OtherActor, 5);
	}
	activated = true;
	if(GetWorld())
	{
		//Get all the doors
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), ADoor::StaticClass(), Doors);

		//Get distance from first door
		float leastDistance = FVector::Dist(GetActorLocation(), Doors[0]->GetActorLocation());

		//Iterate through all the doors
		for(int i = 0; i < Doors.Num(); i++)
		{
			//Get distance from current door to this scanner
			float currDistance = FVector::Dist(GetActorLocation(), Doors[i]->GetActorLocation());
			
			if(currDistance <= leastDistance)
			{
				Door = Cast<ADoor>(Doors[i]);
				leastDistance = currDistance;
			}
		}
	}
}

void AScanner::NotifyActorEndOverlap(AActor* OtherActor)
{
	Super::NotifyActorEndOverlap(OtherActor);
	UpdateScreen(OtherActor, 4);
	activated = false;
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
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Red, "No Door to open");
	}
}

bool AScanner::CheckActivation(){return activated;}



