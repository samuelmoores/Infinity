// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"

#include <string>

#include "InputTriggers.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "EnhancedInputComponent.h"
#include "Math/UnitConversion.h"


// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(RootComponent);
	
}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

}

void APlayerCharacter::MoveForward(float value)
{
	FVector playerLocation = GetActorLocation();
	
	playerLocation += GetActorForwardVector() * value * moveSpeed;
	SetActorLocation(playerLocation);
	
}

void APlayerCharacter::MoveRight(float value)
{
	FVector playerLocation = GetActorLocation();

	playerLocation += GetActorRightVector() * value * moveSpeed;
	SetActorLocation(playerLocation);
	
}

void APlayerCharacter::Rotate(float value)
{
	auto playerRotation = GetController()->GetControlRotation();

	playerRotation.Yaw += value * rotationSpeed;

	GetController()->SetControlRotation(playerRotation);
	
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
	PlayerInputComponent->BindAxis(TEXT("Rotation"), this, &APlayerCharacter::Rotate);

}




