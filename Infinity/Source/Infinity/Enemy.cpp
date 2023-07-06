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
	hit = false;
	attacking = false;
	health = 1.0f;
	isBlocking = false;
	isDead = false;
	destroyLifetime = 5.0f;

}

void AEnemy::TakeDamage(float damageAmount)
{

	
	if(health < 0.1f)
	{
		health = 0.0f;
		FString num = FString::SanitizeFloat(health);
		GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Red, num);

		isDead = true;
		GetWorldTimerManager().SetTimer(Timer, this, &AEnemy::Death, GetWorld()->GetDeltaSeconds(), true);
		
	}else if(health > 1.0f)
	{
		health = 1.0f;
	}
	else
	{
		health -= damageAmount;
		FString num = FString::SanitizeFloat(health);
		GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Yellow, num);

	}

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
		hit = true;
	}

	
	
}

void AEnemy::NotifyActorEndOverlap(AActor* OtherActor)
{
	Super::NotifyActorEndOverlap(OtherActor);

	if(OtherActor->ActorHasTag("Hitbox"))
	{
		hit = false;
	}
	
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

	//GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Yellow, "Attack");
	
	attacking = true;
	
}

void AEnemy::Death()
{
	destroyLifetime -= GetWorld()->GetDeltaSeconds();

	if(destroyLifetime <= 0.0f)
	{
		Destroy();
		GetWorldTimerManager().ClearTimer(Timer);
	}
}


