// Fill out your copyright notice in the Description page of Project Settings.


#include "Computer.h"

AComputer::AComputer()
{
	bool incrementing = true;

	
}

void AComputer::TurnOnScreen()
{
	Mesh->SetMaterial(1, Mesh->GetMaterial(3));
	
}

void AComputer::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

}

void AComputer::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Super::OnOverlapBegin(OverlappedComp, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);

	TurnOnScreen();
}
