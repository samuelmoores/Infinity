// Copyright Epic Games, Inc. All Rights Reserved.

#include "InfinityCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Gun.h"
#include "HitBox.h"
#include "Scanner.h"
#include "Kismet/GameplayStatics.h"
#include "Particles/ParticleSystem.h"

//////////////////////////////////////////////////////////////////////////
// AInfinityCharacter

AInfinityCharacter::AInfinityCharacter()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);
		
	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.0f, 0.0f); // ...at this rotation rate

	// Note: For faster iteration times these variables, and many more, can be tweaked in the Character Blueprint
	// instead of recompiling to adjust them
	GetCharacterMovement()->JumpZVelocity = 700.f;
	GetCharacterMovement()->AirControl = 0.35f;
	GetCharacterMovement()->MaxWalkSpeed = 500.f;
	GetCharacterMovement()->MinAnalogWalkSpeed = 20.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 400.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	Knife = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Knife"));
	Knife->SetupAttachment(GetMesh(), "hand_r_knife_SOC");
	
	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named ThirdPersonCharacter (to avoid direct content references in C++)

	Interactable = nullptr;

	//Player does not start with a weapon
	hasWeapon = false;

	//Initialize shooting boolean
	shooting = false;

	//Player starts not interacting
	interacting = false;
	hasKeycard = false;

	//Player starts with first weapon selected
	selectedWeaponIndex = 0;

	//The player can have up to 3 weapons
	Weapons.Add(nullptr);
	Weapons.Add(nullptr);
	Weapons.Add(nullptr);
	Weapons.Add(nullptr);

	//Set health bar
	health = 1.0f;

	isHit = false;

	attacking = false;

	isDodging = false;

}

void AInfinityCharacter::BeginPlay()
{
	// Call the base class  
	Super::BeginPlay();

	dodgeTimer = 2.0f;

	//Add Input Mapping Context
	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}
	}
	
	UGameplayStatics::GetAllActorsWithTag(GetWorld(), "Interactable", Interactables);

}

void AInfinityCharacter::Tick(float DeltaSeconds)
{
	dodgeTimer -= DeltaSeconds;
	FString mes = FString::SanitizeFloat(dodgeTimer);
	GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Yellow, mes);
	if(dodgeTimer < 0.0f)
		dodgeTimer = 0.0f;

}

void AInfinityCharacter::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);
	if(OtherActor->ActorHasTag("Interactable"))
	{
		canInteract = true;
		Interactable = OtherActor;
	}
	if(OtherActor->ActorHasTag("HitboxEnemy"))
	{
		if(attacking || isDodging)
		{
			isHit = false;
			health -= 0.15f;
		}
		else
		{
			isHit = true;
			health -= 0.35f;
		}
		
		if(health <= 0.0f)
		{
			isDead = true;
			GetCharacterMovement()->DisableMovement();
			GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
			health = 0.0f;
		}
	}
}

void AInfinityCharacter::NotifyActorEndOverlap(AActor* OtherActor)
{
	Super::NotifyActorEndOverlap(OtherActor);
	if(OtherActor->ActorHasTag("Interactable"))
		canInteract = false;
}

void AInfinityCharacter::Jump()
{
	if(!attacking)
		Super::Jump();
}

//////////////////////////////////////////////////////////////////////////
// Input

void AInfinityCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// Set up action bindings
	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent)) {
		
		//Jumping
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Triggered, this, &ACharacter::Jump);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);

		//Moving
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AInfinityCharacter::Move);

		//Looking
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &AInfinityCharacter::Look);

		//Shooting
		EnhancedInputComponent->BindAction(ShootAction, ETriggerEvent::Started, this, &AInfinityCharacter::Shoot);
		EnhancedInputComponent->BindAction(ShootAction, ETriggerEvent::Completed, this, &AInfinityCharacter::StopShoot);
		
		//Aiming
		PlayerInputComponent->BindAction("Aim", IE_Pressed, this, &AInfinityCharacter::StartAim);
		PlayerInputComponent->BindAction("Aim", IE_Released, this, &AInfinityCharacter::StopAim);

		//Interacting
		PlayerInputComponent->BindAction("Interact", IE_Pressed, this, &AInfinityCharacter::StartInteract);
		PlayerInputComponent->BindAction("Interact", IE_Released, this, &AInfinityCharacter::StopInteract);

		//Changing Weapons
		PlayerInputComponent->BindAction("ChangeWeapon", IE_Pressed, this, &AInfinityCharacter::ChangeWeapon);

		//Dodging
		PlayerInputComponent->BindAction("Dodge", IE_Pressed, this, &AInfinityCharacter::Dodge);
	}

}

void AInfinityCharacter::Move(const FInputActionValue& Value)
{

	// input is a Vector2D
	FVector2D MovementVector = Value.Get<FVector2D>();

	if (Controller != nullptr && !isHit)
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	
		// get right vector 
		const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		// add movement 
		AddMovementInput(ForwardDirection, MovementVector.Y);
		AddMovementInput(RightDirection, MovementVector.X);
	}
}

void AInfinityCharacter::Look(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D LookAxisVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		// add yaw and pitch input to controller
		AddControllerYawInput(LookAxisVector.X);
		AddControllerPitchInput(LookAxisVector.Y);
	}
}

void AInfinityCharacter::StartAim()
{
	if(hasWeapon)
	{
		aiming = true;
		GetCharacterMovement()->MaxWalkSpeed = 150.0f;
		CameraBoom->TargetArmLength = 75.0f;
		CameraBoom->SocketOffset = FVector(0.0f, 50.0f, 30.0f);
		FollowCamera->bUsePawnControlRotation = true;
		GetCharacterMovement()->bOrientRotationToMovement = false;
		bUseControllerRotationYaw = true;
	}
}

void AInfinityCharacter::StopAim()
{
	aiming = false;
	GetCharacterMovement()->MaxWalkSpeed = 500.0f;
	CameraBoom->TargetArmLength = 400.0f;
	CameraBoom->SocketOffset = FVector(0.0f, 0.0f, 0.0f);
	FollowCamera->bUsePawnControlRotation = false;
	GetCharacterMovement()->bOrientRotationToMovement = true;
	bUseControllerRotationYaw = false;
}

void AInfinityCharacter::Shoot()
{
	if(aiming && hasWeapon && selectedWeaponIndex != 0)
	{
		//Player is now shooting
		shooting = true;
		//Find where the shot begins and where the shot ends
		FVector StartLocation = FollowCamera->GetComponentLocation(); 
		FVector EndLocation = FollowCamera->GetComponentLocation() + FollowCamera->GetForwardVector() * 10000;
		if(Gun)
		{
			Gun->SpawnMuzzleFlash();
			Gun->Shoot(StartLocation, EndLocation);
		}
	}
}

void AInfinityCharacter::StopShoot()
{
	shooting = false;
}

void AInfinityCharacter::StartInteract()
{
	interacting = true;

	//Does the player have something to interact with
	if(Interactable && canInteract)
	{
		/////////////////Is it a keycard//////////////////////////////
		if(Interactable->ActorHasTag("KeyCard"))
		{
			hasKeycard = true;
			Interactable->Destroy();
		}
		
		////////////////Is it a scanner/////////////////////////////////
		if(Interactable->ActorHasTag("Scanner"))
		{
			//Does the player have a keycard to open the door with the scanner
			Scanner = Cast<AScanner>(Interactable);
			if(Scanner && hasKeycard)
			{
				Scanner->OpenDoor();
			}
		}

		///////////////Is it a pistol or rifle/////////////////////////////
		if(Interactable->ActorHasTag("Pistol") || Interactable->ActorHasTag("Rifle"))
		{
			if(selectedWeaponIndex == 0)
			{
				ChangeWeapon();
			}
				
			//Check if the selceted slot is empty
			if(Weapons[selectedWeaponIndex] == nullptr)
			{
				Gun = Cast<AGun>(Interactable);
				if(Gun)
				{
					if(Gun->GetCanInteract())
					{
						//If it is, attach it to the player and add it to the inventory UI
						Gun->AttachToPlayer(this, Gun);
						hasWeapon = true;
						Weapons[selectedWeaponIndex] = Gun;
						Weapons[selectedWeaponIndex]->SetActorEnableCollision(false);
					}
				}
			}
		}
	}
}

void AInfinityCharacter::StopInteract()
{
	interacting = false;
}

void AInfinityCharacter::ChangeWeapon()
{
	switch(selectedWeaponIndex)
	{
	case 0:
		{
			SetWeapon(Weapons);
			break;
		}
	case 1:
		{
			SetWeapon(Weapons);
			break;
		}
	case 2:
		{
			SetWeapon(Weapons);
			break;
		}
	case 3:
		{
			SetWeapon(Weapons);
			break;
		}
	default:
		{
			
		}
	}
}

void AInfinityCharacter::SetWeapon(TArray<AWeapon*> WeaponsInventory)
{
	//Check outgoing inventory slot
	if(WeaponsInventory[selectedWeaponIndex])
	{
		Gun = Cast<AGun>(Weapons[selectedWeaponIndex]);
		if(Gun)
			Gun->UnequipGun(this);
		hasWeapon = false;
	}//if the knife was in the outgoing inventory slot
	else if(selectedWeaponIndex == 0)
	{
		Knife->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetIncludingScale, "calf_l_SOC");
	}
	//Move selection clamp between 0 and 2
	if(selectedWeaponIndex == 3)
	{
		Knife->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetIncludingScale, "hand_r_knife_SOC");
		selectedWeaponIndex = 0;
	}
	else
	{
		selectedWeaponIndex++;
	}
	//Check incoming inventory slot
	if(WeaponsInventory[selectedWeaponIndex])
	{
		Gun = Cast<AGun>(Weapons[selectedWeaponIndex]);
		if(Gun)
			Gun->AttachToPlayer(this, Gun);
		hasWeapon = true;
	}
	else
	{
		hasWeapon = false;
	}
}

void AInfinityCharacter::Dodge()
{
		if(!isDodging && dodgeTimer <= 0.0f)
		{
			isDodging = true;
			dodgeTimer = 1.2f;
		}

}

void AInfinityCharacter::Attack()
{
	if(selectedWeaponIndex == 0)
	{
		attacking = true;
	}
}

float AInfinityCharacter::GetHealth()
{
	return health;
}





