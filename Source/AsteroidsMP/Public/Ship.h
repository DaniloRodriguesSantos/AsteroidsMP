// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Hitable.h"
#include "IAttackable.h"
#include "InputActionValue.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Character.h"
#include "Ship.generated.h"

UCLASS()
class ASTEROIDSMP_API AShip : public APawn, public IAttackable, public IHitable
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AShip();

private:
	FTransform OriginPoint;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:

	UPROPERTY(EditDefaultsOnly, Category=Ship)
	UStaticMeshComponent* MeshComp;

	UPROPERTY(EditDefaultsOnly, Category=Ship)
	UBoxComponent* CollisionComp;
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(Server, Reliable)
	virtual void Attack() override;

	UFUNCTION(Server, Reliable)
	void Rotate(float Value);

	UPROPERTY(EditDefaultsOnly)
	float RotationForce;

	UPROPERTY(EditDefaultsOnly)
	float ThrustForce;
	
	UFUNCTION(Server, Reliable)
	void Thrust();

	UFUNCTION(Server, Reliable)
	void HyperspaceJump();

	virtual void ReceiveDamage() override;
	void Respawn();
	void Die();
};
