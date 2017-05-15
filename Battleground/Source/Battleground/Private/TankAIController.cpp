// Fill out your copyright notice in the Description page of Project Settings.

#include "Battleground.h"
#include "Tank.h"
#include "Projectile.h"
#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector HitLocation = FVector(0);
	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControlledTank = Cast<ATank>(GetPawn());
	if (PlayerTank) 
	{
		//TODO Move towards the player
		//Aim towards the player
		ControlledTank->AimAt(PlayerTank->GetActorLocation());

		ControlledTank->TankFire(); // TODO limit firing rate.
	}
}