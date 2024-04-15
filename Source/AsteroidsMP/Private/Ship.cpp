// Fill out your copyright notice in the Description page of Project Settings.


#include "Ship.h"

#include "AMPFunctionLibrary.h"
#include "AMPPlayerState.h"
#include "ShootComponent.h"
#include "Kismet/KismetSystemLibrary.h"

// Sets default values
AShip::AShip()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	RotationForce = 9500.f;
	ThrustForce = 600.f;
	bReplicates = true;
	SetReplicatingMovement(true);

	// Create Mesh Component
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	
	// Set as root component
	RootComponent = MeshComp;
	
	// Use a sphere as a simple collision representation
	CollisionComp = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComp"));

	// Players can't walk on it
	CollisionComp->SetWalkableSlopeOverride(FWalkableSlopeOverride(WalkableSlope_Unwalkable, 0.f));
	CollisionComp->CanCharacterStepUpOn = ECB_No;

	CollisionComp->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AShip::BeginPlay()
{
	Super::BeginPlay();
	OriginPoint = GetActorTransform();
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

void AShip::Attack_Implementation()
{
	IAttackable::Attack();
	UShootComponent* ShootComponent = GetComponentByClass<UShootComponent>();
	if(ShootComponent != nullptr)
	{
		ShootComponent->Shoot();
	}
}

void AShip::Rotate_Implementation(float Value)
{
	MeshComp->AddTorqueInRadians(FVector(0.f, 0.f, 95000.0f * Value));
}

void AShip::Thrust_Implementation()
{
	MeshComp->AddImpulse(FVector(GetActorForwardVector() * ThrustForce));
}

void AShip::HyperspaceJump_Implementation()
{
	MeshComp->SetSimulatePhysics(false);
	SetActorLocation(UAMPFunctionLibrary::GetRandPointInArena());
	MeshComp->SetSimulatePhysics(true);
}

void AShip::ReceiveDamage()
{
	IHitable::ReceiveDamage();
	AAMPPlayerState* CurrentPlayerState = Cast<AAMPPlayerState>(GetPlayerState());
	if(CurrentPlayerState)
	{
		CurrentPlayerState->DecreaseHealth();
		if(CurrentPlayerState->GetHealth() > 0)
		{
			Respawn();
		}
		else
		{
			Die();	
		}
	}else
	{
		UKismetSystemLibrary::PrintString(this,
					FString::Printf(TEXT("PlayerState is not valid!")));
	}

}

void AShip::Respawn()
{
	UPrimitiveComponent* physicsComponent = Cast<UPrimitiveComponent>(GetRootComponent());
	physicsComponent->SetSimulatePhysics(false);
	SetActorLocationAndRotation(OriginPoint.GetTranslation(), OriginPoint.GetRotation());
	physicsComponent->SetSimulatePhysics(true);
}

void AShip::Die()
{
	UE_LOG(LogTemp, Warning, TEXT("End Game!"));
}



