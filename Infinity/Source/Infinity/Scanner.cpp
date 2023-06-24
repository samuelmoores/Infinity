// Fill out your copyright notice in the Description page of Project Settings.


#include "Scanner.h"

void AScanner::TurnOnScreen(bool canEnter)
{
	if(canEnter)
	{
		Mesh->SetMaterial(0, Mesh->GetMaterial(4));
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, "You no enter");
		
	}
	else
	{
		Mesh->SetMaterial(0, Mesh->GetMaterial(5));

	}
}
