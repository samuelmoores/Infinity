// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Enemy.generated.h"

UCLASS()
class INFINITY_API AEnemy : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemy();

	UFUNCTION(BlueprintCallable)
	void TakeDamage(float damageAmount);

	UFUNCTION(BlueprintCallable)
	float SetHealthBar();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void NotifyActorBeginOverlap(AActor* OtherActor) override;
	void NotifyActorEndOverlap(AActor* OtherActor) override;

	UFUNCTION(BlueprintCallable)
	void Attack();

	UFUNCTION(BlueprintCallable)
	void Death();

	UPROPERTY(BlueprintReadOnly)
	bool isBlocking;

	UPROPERTY(BlueprintReadWrite)
	bool hit;

	UPROPERTY(BlueprintReadWrite)
	bool attacking;

	UPROPERTY(BlueprintReadWrite)
	bool isDead;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	class APlayerCharacter* PlayerCharacer;

	class AHitBox* Hitbox;


	FTimerHandle Timer;
	float attackCoolDown;
	float health;

	//time after enemy dies and the object is destroyed
	float destroyLifetime;

};
