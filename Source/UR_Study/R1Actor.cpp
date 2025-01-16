// Fill out your copyright notice in the Description page of Project Settings.


#include "R1Actor.h"
#include "R1Object.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AR1Actor::AR1Actor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// FRotator(y, z, x)

	Body = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Body"));
	RootComponent = Body;
	Body->SetRelativeScale3D(FVector(2, 3, 0.5f));

	Wing = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Wing"));
	Wing->SetupAttachment(Body);
	Wing->SetRelativeScale3D(FVector(3.75f, 0.25f, 0.5f));
	Wing->SetRelativeLocationAndRotation(FVector(55, -72, 80), FRotator(0, 90, 0));

	Head = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Head"));
	Head->SetupAttachment(Body);
	Head->SetRelativeLocationAndRotation(FVector(105, 36, 40), FRotator(0, 0, 0));
	Head->SetRelativeScale3D(FVector(0.25f, 0.25f, 0.25f));

	ConstructorHelpers::FObjectFinder<UStaticMesh> FindMesh(TEXT("/Script/Engine.StaticMesh'/Game/Material/SM_Cube.SM_Cube'"));
	if (FindMesh.Succeeded())
	{
		Body->SetStaticMesh(FindMesh.Object);
		Wing->SetStaticMesh(FindMesh.Object);
		Head->SetStaticMesh(FindMesh.Object);
	}
}

// Called when the game starts or when spawned
void AR1Actor::BeginPlay()
{
	Super::BeginPlay();

	// R1액터이거나 파생된 애들을 찾아오는 함수
	// Target = UGameplayStatics::GetActorOfClass(GetWorld(), AR1Actor::StaticClass());

	// std::vector
	TArray<AActor*> Actors;

	UGameplayStatics::GetAllActorsWithTag(GetWorld(), TEXT("Padak"), Actors);

	// Actors.Empty() <-> v.Clear()
	if (Actors.Num() > 0)
	{
		Target = Actors[0];
	}
}

// Called every frame
void AR1Actor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	float speed = 50.0f;
	float Distance = DeltaTime * speed;

	FVector Location = GetActorLocation();

	FVector DirectionVector = Target->GetActorLocation() - GetActorLocation();
	DirectionVector.Normalize();

	FVector NewLocation = Location + FVector::ForwardVector * Distance;
	//SetActorLocation(NewLocation);

	AddActorWorldOffset(DirectionVector * Distance);
}

