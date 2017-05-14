// Fill out your copyright notice in the Description page of Project Settings.

#include "Battleground.h"
#include "TankBarrel.h"

void UTankBarrel::Elevate(float RelativeSpeed)
{
	//Move the barrel the right amount this frame
	//Given a max elevation speed, and the frame time
	RelativeSpeed = FMath::Clamp(RelativeSpeed, -1.f, 1.f);
	auto ElevationChange = RelativeSpeed*MaxDegreesPerSecond*GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation =RelativeRotation.Pitch + ElevationChange;
	SetRelativeRotation(FRotator(FMath::Clamp(RawNewElevation, MinElevationDegrees, MaxElevationDegrees), 0, 0));
}