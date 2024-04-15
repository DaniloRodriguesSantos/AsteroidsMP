// Fill out your copyright notice in the Description page of Project Settings.


#include "AMPPlayerState.h"

AAMPPlayerState::AAMPPlayerState()
{
	Health = 3;
}

void AAMPPlayerState::IncreaseHealth()
{
	Health++;
	OnHealthChanged.Broadcast();
	UE_LOG(LogTemp, Warning, TEXT("Increased Health! Health now is: %d"), Health);
}

void AAMPPlayerState::DecreaseHealth()
{
	Health--;
	OnHealthChanged.Broadcast();
	UE_LOG(LogTemp, Warning, TEXT("Decreased Health! Health now is: %d"), Health);
	if(Health <= 0)
	{
		bIsDead = false;
	}
}
