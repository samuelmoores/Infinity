// Fill out your copyright notice in the Description page of Project Settings.
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Computer.generated.h"
UCLASS()
class INFINITY_API AComputer : public AActor
{
	GENERATED_BODY()
	UPROPERTY(EditDefaultsOnly)
	class UBoxComponent* BoxCollider;
	UPROPERTY(EditDefaultsOnly)
	UStaticMeshComponent* Mesh;
	bool activated;
public:	
	// Sets default values for this actor's properties
	AComputer();
	void UpdateScreen(int materialIndex);
	UFUNCTION(BlueprintCallable)
	bool CheckActivation();
	void NotifyActorBeginOverlap(AActor* OtherActor) override;
	void NotifyActorEndOverlap(AActor* OtherActor) override;
};




