// Fill out your copyright notice in the Description page of Project Settings.


#include "KeyCard.h"

#include "InfinityCharacter.h"
#include "Components/BoxComponent.h"

// Sets default values
AKeyCard::AKeyCard()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoxCollider = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollider"));
	BoxCollider->SetupAttachment(RootComponent); 

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(BoxCollider);

	rotationSpeed = 75.0f;
	rotation = 0.0f;
	playerOverlapping = false;
}

void AKeyCard::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);
	playerOverlapping = OtherActor->ActorHasTag("Player");
					
}

void AKeyCard::NotifyActorEndOverlap(AActor* OtherActor)
{
	Super::NotifyActorEndOverlap(OtherActor);
	playerOverlapping = !OtherActor->ActorHasTag("Player");

}

// Called every frame
void AKeyCard::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	rotation += DeltaTime;
	Mesh->SetRelativeRotation(FRotator(0.0f, rotation * rotationSpeed, 0.0f));

}

