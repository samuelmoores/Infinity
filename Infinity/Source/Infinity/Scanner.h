// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interactable.h"
#include "Scanner.generated.h"

/**
 * 
 */
UCLASS()
class INFINITY_API AScanner : public AInteractable
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable)
	void TurnOnScreen(bool canEnter);
	
};
