// Copyright Epic Games, Inc. All Rights Reserved.

#include "UR_Study.h"
#include "Modules/ModuleManager.h"

#include "R1LogChannels.h"

class FURStudyModule : public FDefaultGameModuleImpl
{
	virtual void StartupModule() override
	{
		UE_LOG(LogR1, Log, TEXT("Hello World"));
	}

	virtual void ShutdownModule() override
	{

	}
};
IMPLEMENT_PRIMARY_GAME_MODULE( FDefaultGameModuleImpl, UR_Study, "UR_Study" );
