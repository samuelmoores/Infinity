 // Fill out your copyright notice in the Description page of Project Settings.


#include "Pickup.h"

 APickup::APickup()
 {
  PrimaryActorTick.bCanEverTick = true;
 }

 void APickup::BeginPlay()
 {
  Super::BeginPlay();
 }

 void APickup::Tick(float DeltaSeconds)
 {
  Super::Tick(DeltaSeconds);
  Hover(DeltaSeconds);
 }

 void APickup::Hover(float DeltaTime)
 {
  Super::Hover(DeltaTime);
  Mesh->SetWorldScale3D(FVector(4.0f, 4.0f, 4.0f));
 }
