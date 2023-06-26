// Fill out your copyright notice in the Description page of Project Settings.


#include "Scanner.h"

#include "ToolContextInterfaces.h"
#include "Kismet/GameplayStatics.h"
#include "Door.h"

void AScanner::BeginPlay()
{
	Super::BeginPlay();

	TArray<AActor*> FoundActors;

	UGameplayStatics::GetAllActorsWithTag(GetWorld(), FName("Door"), FoundActors);

	for(AActor* Actor : FoundActors)
	{
		Door = Cast<ADoor>(Actor);
		if(Door != NULL)
		{

			break;
		}
	}

	PlayerCharacter = Cast<APlayerCharacter>(UGameplayStatics::GetActorOfClass(GetWorld(), APlayerCharacter::StaticClass()));


}

AScanner::AScanner()
{

}

void AScanner::TurnOnScreen(bool canEnter)
{
	if(canEnter)
	{
		Mesh->SetMaterial(0, Mesh->GetMaterial(4));
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, "You no enter");
		
	}
	else
	{
		Mesh->SetMaterial(0, Mesh->GetMaterial(5));

	}
}

void AScanner::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
                              int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Super::OnOverlapBegin(OverlappedComp, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);

	if(Cast<APlayerCharacter>(OtherActor))
	{
		
		if(FVector::Distance(GetActorLocation(), OtherActor->GetActorLocation()) < 250.0f)
		{
			playerOverlapped = true;
			GetWorldTimerManager().SetTimer(TimerHandle, this, &AScanner::OpenDoor, GetWorld()->GetDeltaSeconds(), true);
			
		}
	}
	
}

void AScanner::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex)
{
	Super::OnOverlapEnd(OverlappedComp, OtherActor, OtherComp, OtherBodyIndex);
}


void AScanner::OpenDoor()
{
	if(PlayerCharacter->isInteracting && PlayerCharacter->canInteract)
	{
		Door->Open();
		PlayerCharacter->isInteracting = false;
	}
}


