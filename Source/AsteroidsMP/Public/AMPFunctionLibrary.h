// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "AMPFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class ASTEROIDSMP_API UAMPFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:	
	UFUNCTION(BlueprintCallable, BlueprintPure)
	static void GetArenaBoundaries(FVector& Origin, FVector& Extents);

	UFUNCTION(BlueprintCallable, BlueprintPure)
	static FVector GetRandPointInArena();
};
