// Fill out your copyright notice in the Description page of Project Settings.


#include "Computer.h"

AComputer::AComputer()
{
	
}

void AComputer::TurnOnScreen()
{
	if(canInteract)
	{
		Mesh->SetMaterial(1, Mesh->GetEditorMaterial(3));
	}
	
}

void AComputer::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	TurnOnScreen();
}
