// Copyright EmbraceIT Ltd.

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
	if (ensure(PlayerTank)) 
	{
		//TODO Move towards the player
		MoveToActor(PlayerTank, AcceptanceRadius); //TODO check radius is in cm
		//Aim towards the player
		ControlledTank->AimAt(PlayerTank->GetActorLocation());

		ControlledTank->TankFire(); // TODO limit firing rate.
	}
}