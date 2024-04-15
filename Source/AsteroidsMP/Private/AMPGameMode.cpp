// Fill out your copyright notice in the Description page of Project Settings.


#include "AMPGameMode.h"
#include "AMPFunctionLibrary.h"

AAMPGameMode::AAMPGameMode()
{
	MaxAsteroidsCount = 12;
}

void AAMPGameMode::BeginPlay()
{
	Super::BeginPlay();
	SpawnAsteroids();
}

void AAMPGameMode::SpawnAsteroids_Implementation()
{
	UE_LOG(LogTemp, Warning, TEXT("Spawning asteroids..."));
	for (int i = 0; i < MaxAsteroidsCount; ++i)
	{
		FVector SpawnLocation = UAMPFunctionLibrary::GetRandPointInArena();
		FRotator SpawnRotation = FRotator();

		//Set Spawn Collision Handling Override
		FActorSpawnParameters ActorSpawnParams;
		ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
		
		GetWorld()->SpawnActor<AAsteroid>(AsteroidClass, SpawnLocation, SpawnRotation, ActorSpawnParams);
	}
	UE_LOG(LogTemp, Warning, TEXT("Asteroids finished spawning!"));
}

void AAMPGameMode::EndGame()
{
	// TODO: Implement End Game Loop
	UE_LOG(LogTemp, Warning, TEXT("Should end game!"))
}
