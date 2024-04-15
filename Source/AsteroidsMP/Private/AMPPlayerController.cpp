// Fill out your copyright notice in the Description page of Project Settings.


#include "AMPPlayerController.h"
#include "EngineUtils.h"
#include "InputMappingContext.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "IAttackable.h"
#include "Camera/CameraActor.h"
#include "Ship.h"
#include "Kismet/KismetSystemLibrary.h"

AAMPPlayerController::AAMPPlayerController()
{
	bAutoManageActiveCameraTarget = false;
	bIsGamePaused = false;
}

void AAMPPlayerController::BeginPlay()
{
	Super::BeginPlay();
	for (TActorIterator<ACameraActor> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		ClientSetViewTarget(*ActorItr);
		break;
	}
}

void AAMPPlayerController::PauseGame_Implementation()
{
	if(!bIsGamePaused)
	{
		bIsGamePaused = true;
		FInputModeUIOnly NewInputMode;
		SetInputMode(NewInputMode);
		SetShowMouseCursor(true);
	}
}

void AAMPPlayerController::ResumeGame_Implementation()
{
	if(bIsGamePaused)
	{
		bIsGamePaused = false;
		FInputModeGameOnly NewInputMode;
		SetInputMode(NewInputMode);
		SetShowMouseCursor(false);
	}
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

void AAMPPlayerController::HyperspaceJump()
{
	if(GetPawn())
	{
		Cast<AShip>(GetPawn())->HyperspaceJump();
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
			Input->BindAction(HyperSpaceAction, ETriggerEvent::Triggered, this, &AAMPPlayerController::HyperspaceJump);
			Input->BindAction(PauseGameAction, ETriggerEvent::Triggered, this, &AAMPPlayerController::PauseGame);
		}
	}
}
