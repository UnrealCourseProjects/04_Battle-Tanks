// Fill out your copyright notice in the Description page of Project Settings.

#include "Battleground.h"
#include "TankPlayerController.h"




void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Controller not possessing a tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Controller possessing: %s"), *ControlledTank->GetName());
	}
	
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshairs();
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshairs()
{
	if (!GetControlledTank()) { return; }

	FVector HitLocation; //Out parameter
	UE_LOG(LogTemp, Warning, TEXT("HitLocaton: %s"), *HitLocation.ToString());

	//Get world location if linetrace through crosshair
	//if it hits the landscape
		//Tell controlled tank to aim at this point
}