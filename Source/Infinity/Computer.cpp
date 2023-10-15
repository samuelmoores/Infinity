// Fill out your copyright notice in the Description page of Project Settings.
#include "Computer.h"
#include "Components/BoxComponent.h"
// Sets default values
AComputer::AComputer()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	BoxCollider = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollider"));
	BoxCollider->SetupAttachment(RootComponent);
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(BoxCollider);
}

void AComputer::UpdateScreen(int materialIndex)
{
	Mesh->SetMaterial(1, Mesh->GetMaterial(materialIndex));
}

bool AComputer::CheckActivation(){return activated;}

void AComputer::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);
	UpdateScreen(3);
	activated = true;
}
void AComputer::NotifyActorEndOverlap(AActor* OtherActor)
{
	Super::NotifyActorEndOverlap(OtherActor);
	activated = false;
}


