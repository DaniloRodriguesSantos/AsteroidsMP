// Fill out your copyright notice in the Description page of Project Settings.


#include "AMPGameState.h"

#include "AMPGameMode.h"
#include "AMPPlayerState.h"

void AAMPGameState::IncreasePlayerScore(APlayerController* PlayerController, float Value)
{
	AAMPPlayerState* CurrentPlayerState = PlayerController->GetPlayerState<AAMPPlayerState>();
	CurrentPlayerState->SetScore(CurrentPlayerState->GetScore() + Value);
	OnScoreChanged.Broadcast();
}

void AAMPGameState::CheckEndGame()
{
	bool bShouldEndGame = true;
	for (APlayerState* State : PlayerArray)
	{
		if(!Cast<AAMPPlayerState>(State)->IsDead())
		{
			bShouldEndGame = false;
			break;
		}
	}

	if(bShouldEndGame)
	{
		GetWorld()->GetAuthGameMode<AAMPGameMode>()->EndGame();
	}
}
