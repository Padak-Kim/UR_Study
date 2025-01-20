// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/R1Player.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

AR1Player::AR1Player()
{
	SpringArm = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
	SpringArm->SetupAttachment(GetCapsuleComponent());

	SpringArm->TargetArmLength = 700.f;
	SpringArm->SetRelativeRotation(FRotator(-30, 0, 0));

	Camera = CreateDefaultSubobject<UCameraComponent>("Camera");
	Camera->SetupAttachment(SpringArm);

	GetMesh()->SetRelativeLocationAndRotation(FVector(0.f, 0.f, -88.f), FRotator(0.f, -90.f, 0.f));
}

void AR1Player::BeginPlay()
{
	Super::BeginPlay();
}

void AR1Player::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
