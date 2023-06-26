// Fill out your copyright notice in the Description page of Project Settings.


#include "Interactable.h"

#include "PlayerCharacter.h"
#include "Components/BoxComponent.h"
#include "Components/SphereComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AInteractable::AInteractable()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(RootComponent);

	SphereCollider = CreateDefaultSubobject<USphereComponent>(TEXT("SphereCollider"));
	SphereCollider->SetupAttachment(Mesh);

	SphereCollider->OnComponentBeginOverlap.AddDynamic(this, &AInteractable::OnOverlapBegin);
	SphereCollider->OnComponentEndOverlap.AddDynamic(this, &AInteractable::OnOverlapEnd);

	
}

// Called when the game starts or when spawned
void AInteractable::BeginPlay()
{
	Super::BeginPlay();

	PlayerCharacter = Cast<APlayerCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	
	
}

// Called every frame
void AInteractable::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AInteractable::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, class AActor* OtherActor,
	class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && (OtherActor != this) && OtherComp)
	{
		PlayerCharacter = Cast<APlayerCharacter>(OtherActor);

		if(PlayerCharacter)	
		{	
			PlayerCharacter->canInteract = true;
		}

	}

}

void AInteractable::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor && (OtherActor != this) && OtherComp)
	{
		PlayerCharacter = Cast<APlayerCharacter>(OtherActor);
		if(PlayerCharacter)
		{
			PlayerCharacter->canInteract = false;
			PlayerCharacter->isInteracting = false;
		}
	}
}


