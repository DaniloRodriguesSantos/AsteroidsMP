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

public:
	UPROPERTY(EditAnywhere)
	TSubclassOf<AAsteroid> AsteroidClass;
	
public:	
	void IncreasePlayerScore(APlayerController* PlayerController, float Value);
};
