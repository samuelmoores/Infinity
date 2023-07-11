// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "EnemyHealthUI.generated.h"

/**
 * 
 */
UCLASS()
class INFINITY_API UEnemyHealthUI : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite)
	float health;
	
	void SetHealth(float h);
	
};
