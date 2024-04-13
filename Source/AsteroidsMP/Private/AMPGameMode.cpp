// Fill out your copyright notice in the Description page of Project Settings.


#include "AMPGameMode.h"

#include "AMPPlayerState.h"

void AAMPGameMode::IncreasePlayerScore(APlayerController* PlayerController, float Value)
{
	APlayerState* PlayerState = PlayerController->GetPlayerState<AAMPPlayerState>();
	PlayerState->SetScore(PlayerState->GetScore() + Value);
	UE_LOG(LogTemp, Warning, TEXT("Current Player Score is: %f"), PlayerState->GetScore());
}
