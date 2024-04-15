// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Asteroid.h"
#include "GameFramework/GameMode.h"
#include "AMPGameMode.generated.h"

/**
 * 
 */
UCLASS()
class ASTEROIDSMP_API AAMPGameMode : public AGameMode
{
	GENERATED_BODY()

	AAMPGameMode();

protected:
	UPROPERTY(EditDefaultsOnly)
	int MaxAsteroidsCount;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AAsteroid> AsteroidClass;

	virtual void BeginPlay() override;
private:
	UFUNCTION(NetMulticast, Reliable)
	void SpawnAsteroids();
	
public:
	void EndGame();
};
