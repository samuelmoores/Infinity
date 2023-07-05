// Fill out your copyright notice in the Description page of Project Settings.


#include "HitBox.h"

// Sets default values
AHitBox::AHitBox()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	overlappingEnemy = false;


}


void AHitBox::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);

	if(OtherActor->ActorHasTag("Enemy"))
	{
		overlappingEnemy = true;
	}
	
}

void AHitBox::NotifyActorEndOverlap(AActor* OtherActor)
{
	Super::NotifyActorEndOverlap(OtherActor);

	if(OtherActor->ActorHasTag("Enemy"))
	{
		overlappingEnemy = false;
	}

}

EHitboxEnum AHitBox::getType()
{
	return hitboxType;
}

// Called when the game starts or when spawned
void AHitBox::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AHitBox::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

