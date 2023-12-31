// Copyright Epic Games, Inc. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "Weapon.h"
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

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"));
	UStaticMeshComponent* Knife;

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

	/** Player must be able to use a scanner*/
	class AScanner* Scanner;
	
	/** Enemy Reference*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Enemy, meta = (AllowPrivateAccess = "true"))
	class AEnemy* Enemy;

	/** Pistol Reference */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Weapons, meta = (AllowPrivateAccess = "true"))
	class AGun* Gun;

	/**Player makes specific decisions for each type of interactable*/
	TArray<AActor*> Interactables;

	/**Interactable reference from overlap*/
	UPROPERTY(BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	AActor* Interactable;

	/**All of the players 3 different weapons that can be carried*/
	UPROPERTY(BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TArray<AWeapon*> Weapons;

	/**Which weapon to equip from the weapon HUD, can be toggled through the weapons array*/
	UPROPERTY(BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	int selectedWeaponIndex;

	/** Does Player Have Weapon in hand, false if dropped or unequiped*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Weapons, meta = (AllowPrivateAccess = "true"))
	bool hasWeapon;

	/** Is Player aiming */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Weapons, meta = (AllowPrivateAccess = "true"))
	bool aiming;

	/** Is player shooting, must be switched off with anim notify once shooting animation ends*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Weapons, meta = (AllowPrivateAccess = "true"))
	bool shooting;

	/** Is player interacting, must be switched off when button is released*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	bool interacting;

	/**Is the player overlapping an interactable*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	bool canInteract;

	/** Does playing have a keycard, and can open door*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	bool hasKeycard;

	UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = "true"));
	bool isDodging;

	UPROPERTY(BlueprintReadOnly, meta = (AllowPrivateAccess = "true"));
	float health;

	UPROPERTY(BlueprintReadOnly, meta = (AllowPrivateAccess = "true"));
	bool isDead;

	UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = "true"));
	bool attacking;

	UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = "true"));
	bool isHit;

public:
	AInfinityCharacter();
		
	// To add mapping context
	virtual void BeginPlay();

	/** Called for movement input */
	void Move(const FInputActionValue& Value);

	/** Called for looking input */
	void Look(const FInputActionValue& Value);
	
	// APawn interface
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

	/** Returns CameraBoom subobject **/
	FORCEINLINE USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE UCameraComponent* GetFollowCamera() const { return FollowCamera; }

	FORCEINLINE const bool GetHasKeycard() const { return hasKeycard; }

	//Overlap Event overrides
	void NotifyActorBeginOverlap(AActor* OtherActor) override;
	void NotifyActorEndOverlap(AActor* OtherActor) override;

	virtual void Jump() override;

	/** Aiming */
	void StartAim();
	void StopAim();

	/** Shooting */
	void Shoot();
	void StopShoot();

	/** Interacting*/
	void StartInteract();
	void StopInteract();

	/*Updates selected weapon for the player HUD*/
	UFUNCTION(BlueprintCallable)
	void ChangeWeapon();
	void SetWeapon(TArray<AWeapon*> WeaponsInventory);

	//Doge rolling with forward impulse
	void Dodge();

	UFUNCTION(BlueprintCallable)
	void Attack();

	//Update health bar on HUD
	UFUNCTION(BlueprintCallable)
	float GetHealth();

};

