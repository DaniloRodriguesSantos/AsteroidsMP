// Fill out your copyright notice in the Description page of Project Settings.


#include "Asteroid.h"

#include "AMPGameMode.h"
#include "AMPPlayerState.h"

// Sets default values
AAsteroid::AAsteroid()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MovementSpeed = 300.0f;
	Health = 3;
}

// Called when the game starts or when spawned
void AAsteroid::BeginPlay()
{
	Super::BeginPlay();
	MovementDirection = FMath::VRand();
	MovementDirection.Set(MovementDirection.X, MovementDirection.Y, 0);
}

// Called every frame
void AAsteroid::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Move(DeltaTime);
}

void AAsteroid::ReceiveDamage()
{
	IHitable::ReceiveDamage();
	Health--;
	UE_LOG(LogTemp, Warning, TEXT("Current asteroid health is: %d"), Health);
	Destroy();
	GetWorld()->GetAuthGameMode<AAMPGameMode>()->IncreasePlayerScore(GetWorld()->GetFirstPlayerController(), 10);
}

void AAsteroid::Move(float DeltaTime)
{
	FVector NewLocation = GetActorLocation() + MovementDirection * MovementSpeed * DeltaTime;
	SetActorLocation(NewLocation);
}

