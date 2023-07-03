// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"

#include "Enemy.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "EnhancedInputComponent.h"
#include "Components/SphereComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	bUseControllerRotationYaw = false;
	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;

	// Create the Spring Arm component
	CameraArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	CameraArm->SetupAttachment(RootComponent);
	CameraArm->bUsePawnControlRotation = false;
	CameraArm->bInheritPitch = false;
	CameraArm->bInheritYaw = false;

	// Create the Camera component and attach it to the Spring Arm
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(CameraArm);
	Camera->bUsePawnControlRotation = false;

	HandCollision = CreateDefaultSubobject<USphereComponent>(TEXT("HandCollider"));
	HandCollision->SetupAttachment(GetMesh(), "hand_r_SOC");

	health = 1.0f;
	hasKeycard = false;
	attackCooldown = 0.67f;
	overlappingEnemy = false;

	
}


// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &APlayerCharacter::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &APlayerCharacter::MoveRight);
	PlayerInputComponent->BindAxis(TEXT("RotationX"), this, &APlayerCharacter::LookX);
	PlayerInputComponent->BindAxis(TEXT("RotationY"), this, &APlayerCharacter::LookY);
	PlayerInputComponent->BindAction(TEXT("Jump"), EInputEvent::IE_Pressed, this, &APlayerCharacter::Jump);
	PlayerInputComponent->BindAction(TEXT("Interact"), EInputEvent::IE_Pressed, this, &APlayerCharacter::Interact);
	PlayerInputComponent->BindAction(TEXT("Attack"), IE_Pressed, this, &APlayerCharacter::Attack);

}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	Enemy = Cast<AEnemy>(UGameplayStatics::GetActorOfClass(GetWorld(), AEnemy::StaticClass()));



}


// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void APlayerCharacter::MoveForward(float value)
{
	// Get how much the camera rotated and zero out pitch and roll
	const FRotator CameraRotation = Camera->GetComponentRotation();
	const FRotator ControlRotation(0, CameraRotation.Yaw, 0);

	// Get forward vector that will rotate the player by however many degrees the camera just rotated
	// to align with the x-axis which is pointing forward
	const FVector ForwardDirection = FRotationMatrix(ControlRotation).GetUnitAxis(EAxis::X);

	// Rotate the player by however many degrees the camera rotated and move along the x axis
	AddMovementInput(ForwardDirection, value * moveSpeed);

}

void APlayerCharacter::MoveRight(float value)
{
	if (Controller != nullptr)
	{
		// find out how much the camera rotated and zero out the pitch and the roll
		const FRotator Rotation = Camera->GetComponentRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get right vector that will rotate the player around z axis, 90 deg from the camera
		// to point along the y-axis which is pointing to the right(+) or left(-)
		const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		// Rotate and move the player to align with their local y-axis which would be toward the right of the camera 
		AddMovementInput(RightDirection, value * rotationSpeed);
	}
}

void APlayerCharacter::LookX(float value)
{

	FRotator NewRotation = CameraArm->GetComponentRotation();
	
	NewRotation.Yaw += value; // Adjust RotationSpeed to control the rotation speed

	//DebugMessage(FColor::Yellow, NewRotation.ToString());


	CameraArm->SetWorldRotation(NewRotation);
	//AddControllerYawInput(value);

}

void APlayerCharacter::LookY(float value)
{
	FRotator NewRotation = CameraArm->GetComponentRotation();
	NewRotation.Pitch += value; // Adjust RotationSpeed to control the rotation speed
	
	CameraArm->SetWorldRotation(NewRotation);

	//AddControllerPitchInput(value);

}

void APlayerCharacter::Jump()
{
	Super::Jump();

}

void APlayerCharacter::DebugMessage(FColor color, FString message)
{
	GEngine->AddOnScreenDebugMessage(-1, 0.5f, color, message);

}

void APlayerCharacter::Interact()
{
	if(!isInteracting && canInteract)
	{
		isInteracting = true;

		
	}
	else
	{
		isInteracting = false;

	}
}

void APlayerCharacter::Attack()
{
	attack = true;

	GetWorldTimerManager().SetTimer(Timer, this, &APlayerCharacter::AttackCoolDown, GetWorld()->GetDeltaSeconds(), true);
	
}

void APlayerCharacter::AttackCoolDown()
{
	attackCooldown -= GetWorld()->GetDeltaSeconds();

	if(overlappingEnemy)
	{
		if(Enemy)
		{
			Enemy->TakeDamage(0.01f);
			
		}

	}
	
	if(attackCooldown <= 0)
	{
		GetWorldTimerManager().ClearTimer(Timer);
		attackCooldown = 0.67f;
		attack = false;
	}
	
}

void APlayerCharacter::NotifyActorBeginOverlap(AActor* OtherActor)
{
	
	
}

void APlayerCharacter::NotifyActorEndOverlap(AActor* OtherActor)
{
	Super::NotifyActorEndOverlap(OtherActor);

	

}





