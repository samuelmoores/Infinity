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
#include "Pistol.h"
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
	
	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named ThirdPersonCharacter (to avoid direct content references in C++)

	//Player does not start with a weapon
	hasWeapon = false;

	//Initialize shooting boolean
	shooting = false;

	//Set Particle System
	static ConstructorHelpers::FObjectFinder<UParticleSystem> SparksFinder(TEXT("/Game/StarterContent/Particles/P_Explosion"));
	if(SparksFinder.Succeeded())
	{
		Sparks = SparksFinder.Object;
	}

	//Player starts not interacting
	interacting = false;

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
}

void AInfinityCharacter::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);

	if(OtherActor->ActorHasTag("Pistol"))
		Pistol = Cast<APistol>(OtherActor);

	if(OtherActor->ActorHasTag("Keycard"))
	{
		hasKeycard = true;
		OtherActor->Destroy();		
	}

	if(OtherActor->ActorHasTag("Scanner"))
		Scanner = Cast<AScanner>(OtherActor);
	
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
		if(Pistol)
			Pistol->SpawnMuzzleFlash();

		//Find where the shot begins and where the shot ends
		FVector StartLocation = FollowCamera->GetComponentLocation(); 
		FVector ShotLocation = FollowCamera->GetComponentLocation() + FollowCamera->GetForwardVector() * 10000;
		FHitResult Hit;
		FCollisionQueryParams QueryParams;

		if(GetWorld())
		{
			//Send out the shot and check if it hits something
			if(GetWorld()->LineTraceSingleByChannel(Hit, StartLocation, ShotLocation, ECC_Pawn, QueryParams))
			{
				FTransform SpawnTransform(Hit.ImpactNormal.Rotation(), Hit.ImpactPoint);
				UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), Sparks, SpawnTransform);
			
				if(Hit.GetActor()->ActorHasTag("Enemy"))
				{
					Enemy = Cast<AEnemy>(Hit.GetActor());
					if(Enemy)
						Enemy->ShotDamage(0.25f);
					else
						GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Yellow, "No Enemy");
				}
			}	
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
	if(Scanner && hasKeycard)
		Scanner->OpenDoor();
}

void AInfinityCharacter::StopInteract()
{
	interacting = false;
}




