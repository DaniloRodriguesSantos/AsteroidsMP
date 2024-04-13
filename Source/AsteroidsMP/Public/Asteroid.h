// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Hitable.h"
#include "GameFramework/Actor.h"
#include "Asteroid.generated.h"

UCLASS()
class ASTEROIDSMP_API AAsteroid : public AActor, public IHitable
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAsteroid();

private:
	FVector MovementDirection;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly)
	float MovementSpeed;

	UPROPERTY(EditDefaultsOnly)
	uint8 Health;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void ReceiveDamage() override;

private:
	void Move(float DeltaTime);
};
