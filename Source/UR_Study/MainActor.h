// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MainActor.generated.h"

class AR1Actor;

UCLASS()
class UR_STUDY_API AMainActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMainActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY()
	TObjectPtr<AR1Actor> Actor;

	// AR1Actor을 상속받은 클래스를 담을 수 있는 그릇 ex) BP_R1Actor
	UPROPERTY()
	TSubclassOf<AR1Actor> ActorClass;
	
};
