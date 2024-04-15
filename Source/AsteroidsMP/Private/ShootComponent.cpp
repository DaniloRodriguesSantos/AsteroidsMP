// Fill out your copyright notice in the Description page of Project Settings.

#include "ShootComponent.h"
#include "AMPProjectile.h"

UShootComponent::UShootComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UShootComponent::BeginPlay()
{
	Super::BeginPlay();
	for (UActorComponent* component : GetOwner()->GetComponentsByTag(USceneComponent::StaticClass(), "ShipMuzzle"))
	{
		USceneComponent* muzzle = Cast<USceneComponent>(component);
		if(muzzle != nullptr)
		{
			Muzzles.Add(muzzle);
		}
	}
}

void UShootComponent::Shoot_Implementation()
{
	//Try and fire a projectile
	if (ProjectileClass != nullptr)
	{
		UWorld* const World = GetWorld();
		if (World != nullptr)
		{
			for (int i = 0; i < Muzzles.Num(); ++i)
			{
				//Set Spawn Collision Handling Override
				FActorSpawnParameters ActorSpawnParams;
				ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
			
				// Spawn the projectile at the muzzle
				World->SpawnActor<AAMPProjectile>(ProjectileClass, Muzzles[i]->GetComponentLocation(), Muzzles[i]->GetComponentRotation(), ActorSpawnParams);
			}
		}
	}
}

