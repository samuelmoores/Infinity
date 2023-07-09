// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "InfinityCharacter.generated.h"


UCLASS(config=Game)
class AInfinityCharacter : public ACharacter
{
	GENERATED_BODY()

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;

	/** Particle System*/
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Particles, meta = (AllowPrivateAccess = "true"))
	UParticleSystem* Sparks;
	
	/** MappingContext */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputMappingContext* DefaultMappingContext;

	/** Jump Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* JumpAction;

	/** Move Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* MoveAction;

	/** Look Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* LookAction;

	/** Sprint Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* SprintAction;

	/** Shoot Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* ShootAction;

public:
	AInfinityCharacter();

	/** Enemy Reference*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Enemy, meta = (AllowPrivateAccess = "true"))
	class AEnemy* Enemy;

	/** Does Player Have Weapon */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Weapons, meta = (AllowPrivateAccess = "true"))
	bool hasWeapon;

	/** Is Player aiming */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Weapons, meta = (AllowPrivateAccess = "true"))
	bool aiming;

	/** Is player shooting, must be switched off with anim notify once shooting animation ends*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Weapons, meta = (AllowPrivateAccess = "true"))
	bool shooting;
	
protected:

	/** Called for movement input */
	void Move(const FInputActionValue& Value);

	/** Called for looking input */
	void Look(const FInputActionValue& Value);

	/** Aiming */
	void StartAim();
	void StopAim();

	/** Shooting */
	void Shoot();
	void StopShoot();
			

protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	// To add mapping context
	virtual void BeginPlay();

public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }
};

