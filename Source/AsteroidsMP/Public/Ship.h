// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "IAttackable.h"
#include "InputActionValue.h"
#include "GameFramework/Character.h"
#include "Ship.generated.h"

UCLASS()
class ASTEROIDSMP_API AShip : public APawn, public IAttackable
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AShip();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void Attack() override;

	UFUNCTION(BlueprintNativeEvent)
	void Rotate(float Value);
	void Rotate_Implementation(float Value);
	
	UFUNCTION(BlueprintNativeEvent)
	void Thrust();
	void Thrust_Implementation();
};
