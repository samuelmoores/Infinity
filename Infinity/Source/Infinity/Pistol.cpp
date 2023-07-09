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

	static ConstructorHelpers::FObjectFinder<UParticleSystem> MuzzleFlashFinder(TEXT("/Game/StarterContent/Particles/P_Explosion"));

	if(MuzzleFlashFinder.Succeeded())
	{
		MuzzleFlash = MuzzleFlashFinder.Object;
	}
	
}

// Called when the game starts or when spawned
void APistol::BeginPlay()
{
	Super::BeginPlay();
	
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
	attachedToPlayer = true;
	AttachPlayerCharacter->hasWeapon = true;
}

void APistol::Hover(float DeltaTime)
{
	if(!attachedToPlayer)
	{
		//Linear Interpolate up and down at a rate of 100
		FVector NewLocation = FMath::Lerp(GetActorLocation(), GetActorLocation() + FVector(0.0f, 0.0f, 100.0f * offset), DeltaTime);
		Mesh->SetWorldLocation(NewLocation);

		//Mesh hovers up and down by 50.0 units
		if(GetActorLocation().Z >= 225.0f)
		{
			offset = -1;

		}else if(GetActorLocation().Z <= 175.0f)
		{
			offset = 1;

		}
	}
}

void APistol::SpawnMuzzleFlash()
{
	FTransform SpawnTransform = GetActorTransform();
	SpawnTransform.SetLocation(SpawnTransform.TransformPosition(MuzzleFlashLocation->GetComponentLocation()));
	SpawnTransform.SetScale3D(MuzzleFlashLocation->GetComponentScale());
	
	UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), MuzzleFlash, SpawnTransform);

	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, SpawnTransform.GetRotation().ToString());
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, GetActorRotation().ToString());

}

void APistol::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);

	//Check for player collision
	if(OtherActor->ActorHasTag("Player"))
	{
		PlayerCharacter = Cast<AInfinityCharacter>(OtherActor);

		if(PlayerCharacter)
		{
			AttachToPlayer(PlayerCharacter);
		}
		
	}
}
