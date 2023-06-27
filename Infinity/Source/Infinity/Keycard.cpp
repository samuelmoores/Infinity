// Fill out your copyright notice in the Description page of Project Settings.


#include "Keycard.h"

#include "PlayerCharacter.h"
#include "Kismet/GameplayStatics.h"

AKeycard::AKeycard()
{
	
}

void AKeycard::BeginPlay()
{
	Super::BeginPlay();
	
	if(GetWorld())
	{
		PlayerCharacter = Cast<APlayerCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
		
	}

}

void AKeycard::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
                              int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Super::OnOverlapBegin(OverlappedComp, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);


	GetWorldTimerManager().SetTimer(TimerHandle, this, &AKeycard::TakeCard, GetWorld()->GetDeltaSeconds(), true);
	
}

void AKeycard::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex)
{
	Super::OnOverlapEnd(OverlappedComp, OtherActor, OtherComp, OtherBodyIndex);
}

void AKeycard::TakeCard()
{
	if(PlayerCharacter->isInteracting)
	{
		PlayerCharacter->hasKeycard = true;
		GetWorldTimerManager().ClearTimer(TimerHandle);
		Destroy();
	}
}
