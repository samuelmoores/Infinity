// Fill out your copyright notice in the Description page of Project Settings.


#include "Door.h"

#include "Components/BoxComponent.h"

// Sets default values
ADoor::ADoor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	BoxCollider = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollider"));
	BoxCollider->SetupAttachment(RootComponent);
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(RootComponent);
	openSpeed = 50.0f;
	openTime = 0.0f;
	openTimeLimit = 4.0f;
	openLocation = FVector(-650.0f,-639.7f, 400.0f);
	closedLocation = FVector(-650.0f,-350.0f,400.0f);
	isOpen = false;
}
void ADoor::Open()
{
	startTime = GetWorld()->GetTimeSeconds();
	GetWorldTimerManager().SetTimer(Timer, this, &ADoor::Move, GetWorld()->GetDeltaSeconds()/openSpeed, true);
}
void ADoor::Move()
{
	float elapsedTime = GetWorld()->GetTimeSeconds() - startTime;
	if(elapsedTime < 1.0f)
	{
		float Alpha = FMath::Clamp(elapsedTime, 0.0f, 1.0f);
		Mesh->SetWorldLocation(FMath::Lerp(closedLocation, openLocation, Alpha));
	}
	else if(elapsedTime > 2.0f && elapsedTime < 3.0f)
	{
		float Alpha = FMath::Clamp(elapsedTime - 2.0f, 0.0f, 1.0f);
		Mesh->SetWorldLocation(FMath::Lerp(openLocation, closedLocation, Alpha));
	}
}
// Called when the game starts or when spawned
void ADoor::BeginPlay()
{
	Super::BeginPlay();
}
// Called every frame
void ADoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

