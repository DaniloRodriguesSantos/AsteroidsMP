// Fill out your copyright notice in the Description page of Project Settings.


#include "AMPFunctionLibrary.h"

#include "Kismet/KismetMathLibrary.h"

void UAMPFunctionLibrary::GetArenaBoundaries(FVector& Origin, FVector& Extents)
{
	// TODO: This values should be related to main camera's view
	Origin = FVector(4837.f, -8600.f, 0.f);
	Extents = FVector(-4837.f, 8600.f, 0.f);
}

FVector UAMPFunctionLibrary::GetRandPointInArena()
{
	FVector RandomPoint = FVector();
	FVector ArenaCenter = FVector();
	FVector ArenaExtents = FVector();
	GetArenaBoundaries(ArenaCenter, ArenaExtents);

	RandomPoint = UKismetMathLibrary::RandomPointInBoundingBox(ArenaCenter / 2.f, ArenaCenter - ArenaExtents);
	RandomPoint.Set(RandomPoint.X, RandomPoint.Y, 92.f);

	return RandomPoint;
}
