// Fill out your copyright notice in the Description page of Project Settings.


#include "Scanner.h"

#include "Door.h"
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
	if(FrontDoor)
		FrontDoor->Open();
}

// Called when the game starts or when spawned
void AScanner::BeginPlay()
{
	Super::BeginPlay();
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ADoor::StaticClass(), Doors);
	for(int i = 0; i < Doors.Num(); i++)
	{
		if(Doors[i]->ActorHasTag("FrontDoor"))
			FrontDoor = Cast<ADoor>(Doors[i]);
	}
}

void AScanner::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);
	UpdateScreen(OtherActor, 5);
	activated = true;
}

void AScanner::NotifyActorEndOverlap(AActor* OtherActor)
{
	Super::NotifyActorEndOverlap(OtherActor);
	UpdateScreen(OtherActor, 4);
	activated = false;
}

// Called every frame
void AScanner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

