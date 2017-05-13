// Fill out your copyright notice in the Description page of Project Settings.

#include "Battleground.h"
#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto PlayerTank = GetPlayerTank();
	auto AIControlledTank = GetAIControlledTank();

	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Controlled Tank does not see player!"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI %s sees Player %s"), *AIControlledTank->GetName(), *PlayerTank->GetName());
	}
	
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector HitLocation = FVector(0);
	if (GetPlayerTank())
	{
		//TODO Move towards the player
		//Aim towards the player
		GetAIControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
	}
}

ATank * ATankAIController::GetAIControlledTank() const
{
	return Cast<ATank>(GetPawn());
}
 
ATank * ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn)
	{
		return nullptr;
	}
	else
	{
		return Cast<ATank>(PlayerPawn);
	}
	
}