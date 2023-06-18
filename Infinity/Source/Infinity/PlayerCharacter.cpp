// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"

#include <string>

#include "InputTriggers.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "EnhancedInputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Math/UnitConversion.h"


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
	
	
}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();


}

void APlayerCharacter::MoveForward(float value)
{
	// Find out which way is forward relative to the camera
	const FRotator CameraRotation = Camera->GetComponentRotation();
	const FRotator ControlRotation(0, CameraRotation.Yaw, 0);

	// Get forward vector
	const FVector ForwardDirection = FRotationMatrix(ControlRotation).GetUnitAxis(EAxis::X);

	// Add movement in the forward direction
	AddMovementInput(ForwardDirection, value);

}

void APlayerCharacter::MoveRight(float value)
{
	if (Controller != nullptr)
	{
		// find out which way is forward
		const FRotator Rotation = Camera->GetComponentRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		//FString FloatString = FString::Printf(TEXT("%.2f"), Rotation.Yaw); // Convert float to FString with 2 decimal places
		//FString DebugMessage = TEXT("Yaw Rotation: ") + FloatString;
		//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, DebugMessage);

		// get right vector 
		const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		// add movement 
		AddMovementInput(RightDirection, value);
	}
}

void APlayerCharacter::Rotate(float value)
{
	//AddControllerYawInput(value * rotationSpeed);
}

void APlayerCharacter::LookX(float value)
{

	FRotator NewRotation = CameraArm->GetComponentRotation();
	
	NewRotation.Yaw += value; // Adjust RotationSpeed to control the rotation speed

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

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &APlayerCharacter::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &APlayerCharacter::MoveRight);
	PlayerInputComponent->BindAxis(TEXT("RotationX"), this, &APlayerCharacter::LookX);
	PlayerInputComponent->BindAxis(TEXT("RotationY"), this, &APlayerCharacter::LookY);
	//Jumping
	PlayerInputComponent->BindAction(TEXT("Jump"), EInputEvent::IE_Pressed, this, &APlayerCharacter::Jump);

}




