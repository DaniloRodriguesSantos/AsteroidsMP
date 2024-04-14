// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Hitable.h"
#include "GameFramework/Actor.h"
#include "Asteroid.generated.h"

UENUM(BlueprintType)
enum EAsteroidSize
{
	Big = 2,
	Medium = 1,
	Small = 0
};

UCLASS()
class ASTEROIDSMP_API AAsteroid : public AActor, public IHitable
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAsteroid();
	void Init(EAsteroidSize InSize);

private:
	FVector MovementDirection;
	EAsteroidSize Size;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	float MovementSpeed;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void ReceiveDamage() override;

private:
	void Move(float DeltaTime);
	float GetSpeedBySize() const;

	UFUNCTION()
	void OnHit(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
