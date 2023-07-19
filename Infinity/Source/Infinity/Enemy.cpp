// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy.h"

#include "HitBox.h"
#include "KeyCard.h"
#include "Components/CapsuleComponent.h"
#include "Components/WidgetComponent.h"
#include "Engine/DamageEvents.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AEnemy::AEnemy()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	attackCoolDown = 1.0f;
	hit = false;
	attacking = false;
	health = 1.0f;
	blocking = false;
	dead = false;
	destroyLifetime = 15.0f;
	hasKeycard = false;
	isHit = false;


}

void AEnemy::ShotDamage(float damageAmount)
{
	health -= damageAmount;
	isHit = true;
	GetCharacterMovement()->StopActiveMovement();

	
	if(health < 0.1f)
	{
		if(hasKeycard)
		{
			FActorSpawnParameters spawnParams;
			GetWorld()->SpawnActor<AKeyCard>(Keycard, GetActorLocation(), GetActorRotation());
		}
		
		health = 0.0f;
		dead = true;
		GetCharacterMovement()->DisableMovement();
		GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		GetWorldTimerManager().SetTimer(Timer, this, &AEnemy::Death, GetWorld()->GetDeltaSeconds(), true);
	}
}

float AEnemy::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator,
                         AActor* DamageCauser)
{
	health -= DamageAmount;
	isHit = true;
	GetCharacterMovement()->StopActiveMovement();

	if(health < 0.1f)
	{
		if(hasKeycard)
		{
			FActorSpawnParameters spawnParams;
			GetWorld()->SpawnActor<AKeyCard>(Keycard, GetActorLocation(), GetActorRotation());
		}
		
		health = 0.0f;
		dead = true;
		GetCharacterMovement()->DisableMovement();
		GetMesh()->SetSimulatePhysics(true);
		GetMesh()->SetCollisionEnabled(ECollisionEnabled::PhysicsOnly);
		GetMesh()->AddImpulse(GetActorForwardVector()*-2500, NAME_None, true);
		GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		GetWorldTimerManager().SetTimer(Timer, this, &AEnemy::Death, GetWorld()->GetDeltaSeconds(), true);
	}
	
	return Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);
}

float AEnemy::SetHealthBar()
{
	return health;
}

// Called when the game starts or when spawned
void AEnemy::BeginPlay()
{
	Super::BeginPlay();

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


