// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy.h"

#include "HitBox.h"
#include "PlayerCharacter.h"
#include "Components/SphereComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AEnemy::AEnemy()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	HandCollider = CreateDefaultSubobject<USphereComponent>(TEXT("HandCollider"));
	HandCollider->SetupAttachment(GetMesh(), "hand_r_SOC");

	attackCoolDown = 1.0f;
	overlappingEnemy = false;
	attacking = false;
	health = 1.0f;
	isBlocking = false;

}

void AEnemy::TakeDamage(float damageAmount)
{
	FString mes = FString::SanitizeFloat(health);
	
	
	if(health <= 0.0f)
	{
		health = 0.0f;
		
	}else if(health > 1.0f)
	{
		health = 1.0f;
	}
	else
	{
		health -= damageAmount;
	}

	GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Red, mes);
}

float AEnemy::SetHealthBar()
{
	return health;
}

// Called when the game starts or when spawned
void AEnemy::BeginPlay()
{
	Super::BeginPlay();
	PlayerCharacer = Cast<APlayerCharacter>(UGameplayStatics::GetActorOfClass(GetWorld(), APlayerCharacter::StaticClass()));

	
}

void AEnemy::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);

	if(OtherActor->ActorHasTag("Hitbox"))
	{
		overlappingEnemy = true;
	}
	
}

void AEnemy::NotifyActorEndOverlap(AActor* OtherActor)
{
	Super::NotifyActorEndOverlap(OtherActor);
	
}

// Called every frame
void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AEnemy::Attack()
{
	
	
}


