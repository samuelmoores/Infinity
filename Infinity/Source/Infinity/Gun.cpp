// Fill out your copyright notice in the Description page of Project Settings.


#include "Gun.h"

#include "Enemy.h"
#include "InfinityCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "Particles/ParticleSystemComponent.h"

AGun::AGun()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	//Setup Muzzle flash so it's location can be on the end of the pistol mesh
	MuzzleFlashLocation = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("MuzzleFlash"));
	MuzzleFlashLocation->SetupAttachment(RootComponent);

	//Get particle system 
	static ConstructorHelpers::FObjectFinder<UParticleSystem> MuzzleFlashFinder(TEXT("/Game/StarterContent/Particles/P_Explosion"));
	if(MuzzleFlashFinder.Succeeded())
	{
		MuzzleFlash = MuzzleFlashFinder.Object;
	}

	//Set Particle System
	static ConstructorHelpers::FObjectFinder<UParticleSystem> SparksFinder(TEXT("/Game/StarterContent/Particles/P_Explosion"));
	if(SparksFinder.Succeeded())
	{
		HitParticles = SparksFinder.Object;
	}
}

void AGun::UnequipGun(AInfinityCharacter* AttachPlayerCharacter)
{
	if(this->ActorHasTag("Pistol"))
		AttachToComponent(AttachPlayerCharacter->GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, "pelvis_SOC");
	else
	{
		AttachToComponent(AttachPlayerCharacter->GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, "spine02_SOC");
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
