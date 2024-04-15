// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Asteroid.h"
#include "AMPGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class ASTEROIDSMP_API UAMPGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
	TSubclassOf<AAsteroid> AsteroidClass;
};
