// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameState.h"
#include "AMPGameState.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FScoreChanged);

/**
 * 
 */
UCLASS()
class ASTEROIDSMP_API AAMPGameState : public AGameState
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable)
	FScoreChanged OnScoreChanged;
	void IncreasePlayerScore(APlayerController* PlayerController, float Value);

	void CheckEndGame();
};
