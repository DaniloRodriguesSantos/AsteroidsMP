// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameState.h"
#include "AMPGameState.generated.h"

/**
 * 
 */
UCLASS()
class ASTEROIDSMP_API AAMPGameState : public AGameState
{
	GENERATED_BODY()

public:	
	void IncreasePlayerScore(APlayerController* PlayerController, float Value);
};
