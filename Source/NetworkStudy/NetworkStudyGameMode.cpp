// Copyright Epic Games, Inc. All Rights Reserved.

#include "NetworkStudyGameMode.h"
#include "NetworkStudyCharacter.h"
#include "UObject/ConstructorHelpers.h"

ANetworkStudyGameMode::ANetworkStudyGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
