// Copyright Epic Games, Inc. All Rights Reserved.

#include "InfinityGameMode.h"
#include "InfinityCharacter.h"
#include "PlayerCharacter.h"
#include "GameFramework/DefaultPawn.h"
#include "UObject/ConstructorHelpers.h"

AInfinityGameMode::AInfinityGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));

	if (DefaultPawnClass != ADefaultPawn::StaticClass())
	{
		//DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}


