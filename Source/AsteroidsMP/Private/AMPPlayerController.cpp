// Fill out your copyright notice in the Description page of Project Settings.


#include "AMPPlayerController.h"
#include "InputMappingContext.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "IAttackable.h"
#include "Ship.h"

void AAMPPlayerController::BeginPlay()
{
	Super::BeginPlay();
}

void AAMPPlayerController::Fire()
{
	if(GetPawn() && GetPawn()->Implements<UAttackable>())
	{
		Cast<IAttackable>(GetPawn())->Attack();
	}
}

void AAMPPlayerController::Rotate(const FInputActionValue& Value)
{
	if(GetPawn())
	{
		Cast<AShip>(GetPawn())->Rotate(Value.Get<float>());
	}
}

void AAMPPlayerController::Thrust()
{
	if(GetPawn())
	{
		Cast<AShip>(GetPawn())->Thrust();
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
			Input->BindAction(RotateAction, ETriggerEvent::Triggered, this, &AAMPPlayerController::Rotate);
			Input->BindAction(ThrustAction, ETriggerEvent::Triggered, this, &AAMPPlayerController::Thrust);
		}
	}
}
