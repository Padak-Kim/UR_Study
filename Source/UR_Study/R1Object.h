// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "R1Object.generated.h"

/**
 * 
 */
UCLASS()
class UR_STUDY_API UR1Object : public UObject
{
	GENERATED_BODY()
	
public:
	int32 Hp = 100;
	int32 Mp = 40;
	float Speed = 3.5f;
};
