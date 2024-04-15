// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ShootComponent.generated.h"


UCLASS( Blueprintable, BlueprintType, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ASTEROIDSMP_API UShootComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UShootComponent();

	UPROPERTY(EditDefaultsOnly, Category=Projectile)
	TSubclassOf<class AAMPProjectile> ProjectileClass;

protected:
	virtual void BeginPlay() override;

public:
	UFUNCTION(Server, Reliable)
	void Shoot();

private:
	TArray<USceneComponent*> Muzzles;
};
