// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "AMPPlayerState.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FHealthChanged);

/**
 * 
 */
UCLASS()
class ASTEROIDSMP_API AAMPPlayerState : public APlayerState
{
	GENERATED_BODY()

	AAMPPlayerState();
private:
	int Health;
	bool bIsDead;

public:
	UPROPERTY(BlueprintAssignable)
	FHealthChanged OnHealthChanged;
	void IncreaseHealth();
	void DecreaseHealth();
	UFUNCTION(BlueprintPure)
	int GetHealth() const { return Health; }
	bool IsDead() const { return bIsDead; }
	
};
