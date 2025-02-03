// Fill out your copyright notice in the Description page of Project Settings.


#include "R1TextRenderActor.h"

FString AR1TextRenderActor::GetNetMode()
{
	FString NetModeString;
	ENetMode NetMode = GetWorld()->GetNetMode();

	switch (NetMode)
	{
	case NM_Standalone:
		NetModeString = TEXT("NM_Standalone");
		break;
	case NM_DedicatedServer:
		NetModeString = TEXT("NM_DedicatedServer");
		break;
	case NM_ListenServer:
		NetModeString = TEXT("NM_ListenServer");
		break;
	case NM_Client:
		NetModeString = TEXT("NM_Client");
		break;
	case NM_MAX:
		NetModeString = TEXT("NM_MAX");
		break;
	default:
		break;
	}
	return NetModeString;
}
