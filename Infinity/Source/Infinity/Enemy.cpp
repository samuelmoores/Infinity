// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy.h"

#include "HitBox.h"
#include "Components/CapsuleComponent.h"
#include "Components/WidgetComponent.h"
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
	hit = false;

}

// Called when the game starts or when spawned
void AEnemy::BeginPlay()
{
	Super::BeginPlay();

}

void AEnemy::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);

	if(OtherActor->ActorHasTag("HitboxPlayer"))
	{
		if(!attacking)
			hit = true;
		health -= 0.15f;
		if(health <= 0.0f)
		{
			dead = true;
			health = 0.0f;
			GetCharacterMovement()->DisableMovement();
			GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		}
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

void AEnemy::ShotDamage(float damageAmount)
{
	health -= damageAmount;
	if(!attacking)
		hit = true;
	GetCharacterMovement()->StopActiveMovement();
	if(health < 0.1f)
	{
		if(hasKeycard)
		{
		}
		health = 0.0f;
		dead = true;
		GetCharacterMovement()->DisableMovement();
		GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		GetWorldTimerManager().SetTimer(Timer, this, &AEnemy::Death, GetWorld()->GetDeltaSeconds(), true);
	}
}

void AEnemy::Damage(float DamageAmount)
{
	health -= DamageAmount;
	hit = true;
	GetCharacterMovement()->StopActiveMovement();
	if(health < 0.1f)
	{
		if(hasKeycard)
		{
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
}

float AEnemy::SetHealthBar()
{
	return health;
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


