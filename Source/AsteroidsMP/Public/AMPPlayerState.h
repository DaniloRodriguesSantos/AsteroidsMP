// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "AMPPlayerState.generated.h"

/**
 * 
 */
UCLASS()
class ASTEROIDSMP_API AAMPPlayerState : public APlayerState
{
	GENERATED_BODY()

	AAMPPlayerState();
private:
	uint8 Health;

public:
	void IncreaseHealth();
	void DecreaseHealth();
	uint8 GetHealth() const { return Health; };
};
