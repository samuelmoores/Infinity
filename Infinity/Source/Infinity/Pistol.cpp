// Fill out your copyright notice in the Description page of Project Settings.

#include "Pistol.h"
#include "InfinityCharacter.h"
#include "VectorTypes.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Particles/ParticleSystem.h"
#include "Particles/ParticleSystemComponent.h"

// Sets default values
APistol::APistol()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Setup Pistol MEsh for Blueprint
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(RootComponent);

	//Attach Box Collider to Pistol Mesh
	BoxCollider = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollider"));
	BoxCollider->SetupAttachment(Mesh);
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

	canPickup = false;
	LerpDistance = 30.0f;
	LerpSpeed = 50.0f;
	rotation = 0.0f;
	rotationSpeed = 75.0f;

}

// Called when the game starts or when spawned
void APistol::BeginPlay()
{
	Super::BeginPlay();
	if(GetWorld())
	{
		StartingLocationHover = GetActorLocation();
		EndingLocationHover = GetActorLocation() + FVector(0.0f, 0.0f, LerpDistance);
	}
	
}

// Called every frame
void APistol::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//Weapon hovers up and down in the level before being picked up
	Hover(DeltaTime);
}

void APistol::AttachToPlayer(AInfinityCharacter* AttachPlayerCharacter)
{
	//Get the players mesh to access the hand socket and snap the pistol actor to it
	AttachToComponent(AttachPlayerCharacter->GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, "hand_r_SOC");
	BoxCollider->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	attachedToPlayer = true;
	AttachPlayerCharacter->hasWeapon = true;
	Mesh->SetWorldScale3D(FVector(1.0f, 1.0f, 1.0f));


}

void APistol::DetachFromPlayer()
{
	FVector Location = GetActorLocation();
	DetachFromActor(FDetachmentTransformRules::KeepRelativeTransform);
	SetActorLocation(Location);
	attachedToPlayer = false;
	BoxCollider->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	StartingLocationHover = GetActorLocation();
	EndingLocationHover = GetActorLocation() + FVector(0.0f, 0.0f, LerpDistance);

}

void APistol::HolsterPistol(AInfinityCharacter* AttachPlayerCharacter)
{
	AttachToComponent(AttachPlayerCharacter->GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, "pelvis_SOC");
	AttachPlayerCharacter->hasWeapon = false;
}

void APistol::Hover(float DeltaTime)
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
			Mesh->SetWorldScale3D(FVector(3.0f, 3.0f, 3.0f));
		}
	
}

void APistol::SpawnMuzzleFlash()
{
	FTransform SpawnTransform = GetActorTransform();
	SpawnTransform.SetLocation(SpawnTransform.TransformPosition(MuzzleFlashLocation->GetComponentLocation()));
	SpawnTransform.SetScale3D(MuzzleFlashLocation->GetComponentScale());
	
	UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), MuzzleFlash, SpawnTransform);
}

void APistol::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);

	//Check for player collision
	if(OtherActor->ActorHasTag("Player"))
	{
		canPickup = true;
		
	}
}

void APistol::NotifyActorEndOverlap(AActor* OtherActor)
{
	Super::NotifyActorEndOverlap(OtherActor);

	//Check for player collision
	if(OtherActor->ActorHasTag("Player"))
	{
		canPickup = false;
		
	}
}

