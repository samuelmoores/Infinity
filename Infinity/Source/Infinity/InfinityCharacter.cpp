// Copyright Epic Games, Inc. All Rights Reserved.

#include "InfinityCharacter.h"
#include "Enemy.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "KeyCard.h"
#include "Pistol.h"
#include "Scanner.h"
#include "Engine/DamageEvents.h"
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
	
	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named ThirdPersonCharacter (to avoid direct content references in C++)

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

}

void AInfinityCharacter::BeginPlay()
{
	// Call the base class  
	Super::BeginPlay();

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

void AInfinityCharacter::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);
	if(OtherActor->ActorHasTag("Interactable"))
	{
		canInteract = true;
		Interactable = OtherActor;
	}
	
}

void AInfinityCharacter::NotifyActorEndOverlap(AActor* OtherActor)
{
	Super::NotifyActorEndOverlap(OtherActor);
	if(OtherActor->ActorHasTag("Interactable"))
		canInteract = false;
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
		
	}

}

void AInfinityCharacter::Move(const FInputActionValue& Value)
{

	// input is a Vector2D
	FVector2D MovementVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
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
	aiming = true;
	GetCharacterMovement()->MaxWalkSpeed = 150.0f;
	CameraBoom->TargetArmLength = 75.0f;
	CameraBoom->SocketOffset = FVector(0.0f, 50.0f, 30.0f);
	FollowCamera->bUsePawnControlRotation = true;
	GetCharacterMovement()->bOrientRotationToMovement = false;
	bUseControllerRotationYaw = true;
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
	if(aiming && hasWeapon)
	{
		//Player is now shooting
		shooting = true;
		
		//Find where the shot begins and where the shot ends
		FVector StartLocation = FollowCamera->GetComponentLocation(); 
		FVector EndLocation = FollowCamera->GetComponentLocation() + FollowCamera->GetForwardVector() * 10000;
		
		if(Pistol)
		{
			Pistol->SpawnMuzzleFlash();
			Pistol->Shoot(StartLocation, EndLocation);
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
	if(Interactable)
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

		///////////////Is it a pistol/////////////////////////////
		if(Interactable->ActorHasTag("Pistol"))
		{
			Pistol = Cast<APistol>(Interactable);
			if(Pistol)
			{
				if(Pistol->canPickup)
				{
					Pistol->AttachToPlayer(this);
					hasWeapon = true;
					//Add the pistol to which ever weapon slot they have selected
					Weapons[selectedWeaponIndex] = Pistol;
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
	FString mes = FString::SanitizeFloat(selectedWeaponIndex);
	GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Magenta, mes);

	switch(selectedWeaponIndex)
	{
	case 0:
		{
			SetWeapon(Weapons);
			GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Red, "0");
			break;
		}
	case 1:
		{
			SetWeapon(Weapons);
			GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Green, "1");
			break;
		}
	case 2:
		{
			SetWeapon(Weapons);
			GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Yellow, "2");

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
		if(WeaponsInventory[selectedWeaponIndex]->ActorHasTag("Pistol"))
		{
			if(Pistol)
				Pistol->HolsterPistol(this);
			hasWeapon = false;
		}
	}
	
	//Move selection
	if(selectedWeaponIndex == 2)
	{
		selectedWeaponIndex = 0;
	}
	else
	{
		selectedWeaponIndex++;
	}
	
	//Check incoming inventory slot
	if(WeaponsInventory[selectedWeaponIndex])
	{
		if(WeaponsInventory[selectedWeaponIndex]->ActorHasTag("Pistol"))
		{
			if(Pistol)
				Pistol->AttachToPlayer(this);
			hasWeapon = true;
		}
	}

}





