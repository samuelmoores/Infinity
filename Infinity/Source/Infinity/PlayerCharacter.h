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

	UPROPERTY(EditAnywhere)
	class UInputMappingContext* PlayerInput;

	UPROPERTY(EditAnywhere)
	class UInputAction* LookAction;

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
	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
