// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputActionValue.h"
#include "GameFramework/Character.h"
#include "GameFramework/SpringArmComponent.h"
#include "PlayerCharacter.generated.h"

UCLASS()
class INFINITY_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerCharacter();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UCameraComponent* Camera;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class USpringArmComponent* CameraArm;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	class USphereComponent* HandCollision;

	UPROPERTY(EditAnywhere)
	class UInputMappingContext* PlayerInput;

	UPROPERTY(EditAnywhere)
	class UInputAction* LookAction;

	FTimerHandle Timer;

	class AHitBox* Hitbox;

	UPROPERTY(EditAnywhere)
	float rotationSpeed;

	UPROPERTY(EditAnywhere)
	float moveSpeed;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float health;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool isInteracting;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool canInteract;

	bool hasKeycard;

	UPROPERTY(BlueprintReadWrite)
	bool attack;

	UPROPERTY(BlueprintReadWrite)
	bool hit;


	float attackCooldown;
	bool overlappingEnemy;
	class AEnemy* Enemy;

	UFUNCTION(BlueprintCallable)
	void TakeDamage(float damageAmount);


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void MoveForward(float value);
	void MoveRight(float value);
	void LookX(float value);
	void LookY(float value);
	void Jump();
	void DebugMessage(FColor color, FString message);
	void Interact();
	void Attack();
	void AttackCoolDown();
	void NotifyActorBeginOverlap(AActor* OtherActor) override;
	void NotifyActorEndOverlap(AActor* OtherActor) override;
	
	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	

};
