// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TextRenderActor.h"
#include "R1TextRenderActor.generated.h"

/**
 * 
 */
UCLASS()
class NETWORKSTUDY_API AR1TextRenderActor : public ATextRenderActor
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable)
	FString GetNetMode();
};
