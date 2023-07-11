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

	UPROPERTY(BlueprintReadOnly)
	bool blocking;

	UPROPERTY(BlueprintReadWrite)
	bool hit;

	UPROPERTY(BlueprintReadWrite)
	bool attacking;

	UPROPERTY(BlueprintReadWrite)
	bool dead;

	UPROPERTY(BlueprintReadWrite)
	bool shot;

	UPROPERTY(BlueprintReadWrite)
	float health;

	UFUNCTION(BlueprintCallable)
	void ShotDamage(float damageAmount);

	UFUNCTION(BlueprintCallable)
	float SetHealthBar();

	UFUNCTION(BlueprintCallable)
    void Attack();

	UFUNCTION(BlueprintCallable)
	void Death();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void NotifyActorBeginOverlap(AActor* OtherActor) override;
	void NotifyActorEndOverlap(AActor* OtherActor) override;

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
	float destroyLifetime;
};
