// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "PlayerCharacter.h"
#include "InfinityGameMode.generated.h"

UCLASS(minimalapi)
class AInfinityGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AInfinityGameMode();

	void InitGameState() override;

private:
	UPROPERTY(EditAnywhere, NoClear)
	TSubclassOf<APlayerCharacter> CustomPawnClass = APlayerCharacter::StaticClass();

};



