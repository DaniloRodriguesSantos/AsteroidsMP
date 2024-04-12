// Fill out your copyright notice in the Description page of Project Settings.


#include "Ship.h"

#include "ShootComponent.h"

// Sets default values
AShip::AShip()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AShip::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AShip::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AShip::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AShip::Attack()
{
	IAttackable::Attack();
	if(GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, TEXT("This motherfucker should attack!"));
	}
	UShootComponent* ShootComponent = GetComponentByClass<UShootComponent>();
	if(ShootComponent != nullptr)
	{
		ShootComponent->Shoot();
	}
}

void AShip::Rotate_Implementation(float Value)
{
	// Do Something
}

void AShip::Thrust_Implementation()
{
	// Do Something
}



