// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapon.h"

#include "InfinityCharacter.h"
#include "Components/BoxComponent.h"

// Sets default values
AWeapon::AWeapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

void AWeapon::AttachToPlayer(AInfinityCharacter* AttachPlayerCharacter, AWeapon* Weapon)
{
	//Get the players mesh to access the hand socket and snap the pistol actor to it
	if(Weapon->ActorHasTag("Pistol"))
		AttachToComponent(AttachPlayerCharacter->GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, "hand_r_pistol_SOC");
	if(Weapon->ActorHasTag("Rifle"))
		AttachToComponent(AttachPlayerCharacter->GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, "hand_r_rifle_SOC");
	BoxCollider->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	attachedToPlayer = true;
	Mesh->SetWorldScale3D(FVector(1.0f, 1.0f, 1.0f));
}

void AWeapon::DetachFromPlayer()
{
	FVector Location = GetActorLocation();
	DetachFromActor(FDetachmentTransformRules::KeepRelativeTransform);
	SetActorLocation(Location);
	attachedToPlayer = false;
	BoxCollider->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	StartingLocationHover = GetActorLocation();
	EndingLocationHover = GetActorLocation() + FVector(0.0f, 0.0f, LerpDistance);
}





