// Fill out your copyright notice in the Description page of Project Settings.


#include "Scanner.h"

#include "ToolContextInterfaces.h"
#include "Kismet/GameplayStatics.h"
#include "Door.h"

void AScanner::BeginPlay()
{
	Super::BeginPlay();

	TArray<AActor*> FoundActors;

	UGameplayStatics::GetAllActorsWithTag(GetWorld(), FName("Door"), FoundActors);

	for(AActor* Actor : FoundActors)
	{
		Door = Cast<ADoor>(Actor);
		if(Door != NULL)
		{

			break;
		}
	}


	if(PlayerCharacter)
	{
	}

}

AScanner::AScanner()
{

}

void AScanner::TurnOnScreen(bool canEnter)
{
	if(canEnter)
	{
		Mesh->SetMaterial(0, Mesh->GetMaterial(4));
		
	}
	else
	{
		Mesh->SetMaterial(0, Mesh->GetMaterial(5));

	}
}

void AScanner::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
                              int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Super::OnOverlapBegin(OverlappedComp, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);

	
	
}

void AScanner::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex)
{
	Super::OnOverlapEnd(OverlappedComp, OtherActor, OtherComp, OtherBodyIndex);
	playerOverlapped = false;

}


void AScanner::OpenDoor()
{

	
}


