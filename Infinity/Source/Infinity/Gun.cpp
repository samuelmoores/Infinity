// Fill out your copyright notice in the Description page of Project Settings.


#include "Gun.h"

#include "Enemy.h"
#include "InfinityCharacter.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Particles/ParticleSystemComponent.h"

AGun::AGun()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Setup Pistol MEsh for Blueprint
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(RootComponent);

	//Attach Box Collider to Pistol Mesh
	BoxCollider = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollider"));
	BoxCollider->SetupAttachment((Mesh));
	BoxCollider->SetGenerateOverlapEvents(true);

	//Pistol starts hovering up and is not attached to the player
	offset = 1;
	attachedToPlayer = false;

	//Setup Muzzle flash so it's location can be on the end of the pistol mesh
	MuzzleFlashLocation = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("MuzzleFlash"));
	MuzzleFlashLocation->SetupAttachment(RootComponent);

	//Get particle system 
	static ConstructorHelpers::FObjectFinder<UParticleSystem> MuzzleFlashFinder(TEXT("/Game/StarterContent/Particles/P_Explosion"));
	if(MuzzleFlashFinder.Succeeded())
	{
		MuzzleFlash = MuzzleFlashFinder.Object;
	}

	//Pistol spawns and cannot be picked up until overlapped with player
	canPickup = false;

	//Settings that allow pistol to hover and rotate in the level before being picked up
	LerpDistance = 30.0f;
	LerpSpeed = 50.0f;
	rotation = 0.0f;
	rotationSpeed = 75.0f;

	//Set Particle System
	static ConstructorHelpers::FObjectFinder<UParticleSystem> SparksFinder(TEXT("/Game/StarterContent/Particles/P_Explosion"));
	if(SparksFinder.Succeeded())
	{
		HitParticles = SparksFinder.Object;
	}
}

void AGun::BeginPlay()
{

	Super::BeginPlay();
	if(GetWorld())
	{
		StartingLocationHover = GetActorLocation();
		EndingLocationHover = GetActorLocation() + FVector(0.0f, 0.0f, LerpDistance);
	}
}

void AGun::Tick(float DeltaTime)
{
	//Weapon hovers up and down in the level before being picked up
	Hover(DeltaTime);
	GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Yellow, this->GetName());
}

void AGun::Hover(float DeltaTime)
{
	if(!attachedToPlayer)
	{
		float Alpha = FMath::Clamp(DeltaTime, 0.0f, 1.0f);
		//Linear Interpolate up and down at a rate of 100
		FVector NewLocation = FMath::Lerp(GetActorLocation(), GetActorLocation() + FVector(0.0f, 0.0f, LerpSpeed * offset), Alpha);
		Mesh->SetWorldLocation(NewLocation);
		if(NewLocation.Z >= EndingLocationHover.Z)
		{
			offset = -1;
		}else if(NewLocation.Z <= StartingLocationHover.Z)
		{
			offset = 1;
		}
		rotation +=DeltaTime;
		Mesh->SetRelativeRotation(FRotator(0.0f, rotation * rotationSpeed, 0.0f));
		Mesh->SetWorldScale3D(FVector(2.0f, 2.0f, 2.0f));
	}
}

void AGun::NotifyActorBeginOverlap(AActor* OtherActor)
{
	//Check for player collision
	if(OtherActor->ActorHasTag("Player"))
		canPickup = true;
}

void AGun::NotifyActorEndOverlap(AActor* OtherActor)
{
	//Check for end of player collision
	if(OtherActor->ActorHasTag("Player"))
		canPickup = false;
}

void AGun::AttachToPlayer(AInfinityCharacter* AttachPlayerCharacter)
{
	//Get the players mesh to access the hand socket and snap the pistol actor to it
	if(this->ActorHasTag("Pistol"))
		AttachToComponent(AttachPlayerCharacter->GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, "hand_r_pistol_SOC");
	if(this->ActorHasTag("Rifle"))
		AttachToComponent(AttachPlayerCharacter->GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, "hand_r_rifle_SOC");
	BoxCollider->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	attachedToPlayer = true;
	Mesh->SetWorldScale3D(FVector(1.0f, 1.0f, 1.0f));
}

void AGun::DetachFromPlayer()
{
	FVector Location = GetActorLocation();
	DetachFromActor(FDetachmentTransformRules::KeepRelativeTransform);
	SetActorLocation(Location);
	attachedToPlayer = false;
	BoxCollider->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	StartingLocationHover = GetActorLocation();
	EndingLocationHover = GetActorLocation() + FVector(0.0f, 0.0f, LerpDistance);
}

void AGun::UnequipGun(AInfinityCharacter* AttachPlayerCharacter)
{
	if(this->ActorHasTag("Pistol"))
		AttachToComponent(AttachPlayerCharacter->GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, "pelvis_SOC");
	else
	{
		
	}
}

void AGun::Shoot(FVector StartLocation, FVector EndLocation)
{
	FHitResult Hit;
	FCollisionQueryParams QueryParams;

	if(GetWorld())
	{
		//Send out the shot and check if it hits something
		if(GetWorld()->LineTraceSingleByChannel(Hit, StartLocation, EndLocation, ECC_Pawn, QueryParams))
		{
			FTransform SpawnTransform(Hit.ImpactNormal.Rotation(), Hit.ImpactPoint);
			UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), HitParticles, SpawnTransform);
			
			if(Hit.GetActor()->ActorHasTag("Enemy"))
			{
				AEnemy* Enemy = Cast<AEnemy>(Hit.GetActor());
				if(Enemy)
				{
					Enemy->Damage(0.15f);
				}
			}
		}	
	}
}

void AGun::SpawnMuzzleFlash()
{
	FTransform SpawnTransform = GetActorTransform();
	SpawnTransform.SetLocation(SpawnTransform.TransformPosition(MuzzleFlashLocation->GetComponentLocation()));
	SpawnTransform.SetScale3D(MuzzleFlashLocation->GetComponentScale());
	
	UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), MuzzleFlash, SpawnTransform);
}
