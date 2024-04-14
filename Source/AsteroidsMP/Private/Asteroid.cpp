// Fill out your copyright notice in the Description page of Project Settings.


#include "Asteroid.h"

#include "AMPGameMode.h"
#include "AMPPlayerState.h"
#include "Components/SphereComponent.h"
#include "Kismet/KismetSystemLibrary.h"

// Sets default values
AAsteroid::AAsteroid()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Size = EAsteroidSize::Big;
}

void AAsteroid::Init(EAsteroidSize InSize)
{
	Size = InSize;
}

// Called when the game starts or when spawned
void AAsteroid::BeginPlay()
{
	Super::BeginPlay();
	Cast<USphereComponent>(GetComponentByClass(USphereComponent::StaticClass()))->OnComponentBeginOverlap.AddDynamic(this, &AAsteroid::OnHit);
	MovementSpeed = GetSpeedBySize();
	MovementDirection = FMath::VRand();
	MovementDirection.Set(MovementDirection.X, MovementDirection.Y, 0);
}

// Called every frame
void AAsteroid::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Move(DeltaTime);
}

void AAsteroid::ReceiveDamage()
{
	IHitable::ReceiveDamage();
	GetWorld()->GetAuthGameMode<AAMPGameMode>()->IncreasePlayerScore(GetWorld()->GetFirstPlayerController(), 10);
	UWorld* World = GetWorld();
	FTransform spawnTransform = FTransform(GetActorRotation(), GetActorLocation(),FVector(1.f, 1.f, 1.f));
	switch (Size)
	{
	case Big:
		if(World)
		{
			// Define spawn parameters
			//FActorSpawnParameters SpawnParams;
			//SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
			for (int i = 0; i < 2; ++i)
			{
				AAsteroid* SpawnedActor = World->SpawnActorDeferred<AAsteroid>(World->GetAuthGameMode<AAMPGameMode>()->AsteroidClass, spawnTransform);
				SpawnedActor->Init(EAsteroidSize::Medium);
				SpawnedActor->FinishSpawning(spawnTransform);
			}
		}
		// Spawn the projectile at the muzzle
		
		break;
	case Medium:
		if(World)
		{
			// Define spawn parameters
			//FActorSpawnParameters SpawnParams;
			//SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
			for (int i = 0; i < 2; ++i)
			{
				AAsteroid* SpawnedActor = World->SpawnActorDeferred<AAsteroid>(World->GetAuthGameMode<AAMPGameMode>()->AsteroidClass, spawnTransform);
				SpawnedActor->Init(EAsteroidSize::Small);
				SpawnedActor->FinishSpawning(spawnTransform);
			}
		}
		break;
	}
	Destroy();
}

void AAsteroid::Move(float DeltaTime)
{
	FVector NewLocation = GetActorLocation() + MovementDirection * MovementSpeed * DeltaTime;
	SetActorLocation(NewLocation);
}

float AAsteroid::GetSpeedBySize() const
{
	float correctSpeed = 0.f;
	switch (Size)
	{
	case Big:
		correctSpeed = 400.0f;
		break;
	case Medium:
		correctSpeed = 700.0f;
		break;
	case Small:
		correctSpeed = 1000.0f;
		break;
	}

	return correctSpeed;
}

void AAsteroid::OnHit(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor != nullptr && OtherActor != this && !OtherActor->IsA(AAsteroid::StaticClass()) && OtherActor->Implements<UHitable>())
	{
		UKismetSystemLibrary::PrintString(this,
			FString::Printf(TEXT("I'm '%s' and I do implement 'UHitable', give me pain!"), *OtherActor->GetName()));
		Cast<IHitable>(OtherActor)->ReceiveDamage();
		Destroy();
	}
}

