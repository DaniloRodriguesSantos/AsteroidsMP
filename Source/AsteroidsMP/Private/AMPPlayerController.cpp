// Fill out your copyright notice in the Description page of Project Settings.


#include "AMPPlayerController.h"
#include "InputMappingContext.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "IAttackable.h"

void AAMPPlayerController::Fire()
{
	if(GetPawn()->Implements<UAttackable>())
	{
		Cast<IAttackable>(GetPawn())->Attack();
	}
}

void AAMPPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	if(UEnhancedInputLocalPlayerSubsystem* Subsystem =
		ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(InputMapping, 0);
		if(UEnhancedInputComponent* Input = CastChecked<UEnhancedInputComponent>(InputComponent))
		{
			Input->BindAction(FireAction, ETriggerEvent::Triggered, this, &AAMPPlayerController::Fire);
		}
	}
}
