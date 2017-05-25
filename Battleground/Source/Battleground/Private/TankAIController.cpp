// Copyright EmbraceIT Ltd.

#include "Battleground.h"
#include "Projectile.h"
#include "TankAimingComponent.h"
#include "TankAIController.h"
#include "Tank.h" // So we can impliment on death

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	
}

void ATankAIController::SetPawn(APawn* InPawn)
{
	Super::SetPawn(InPawn);
	if (InPawn)
	{
		auto PossessedTank = Cast<ATank>(InPawn);
		if (!ensure(PossessedTank)) { return; }

		// subscribe our loacal method to hte tank's death event
		PossessedTank->OnDeath.AddUniqueDynamic(this, &ATankAIController::OnPossessedTankDeath);
	}
}

void  ATankAIController::OnPossessedTankDeath()
{
	if (!GetPawn()) {return;}
	GetPawn()->DetachFromControllerPendingDestroy();
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector HitLocation = FVector(0);
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	auto ControlledTank = GetPawn();
	if (!ensure(PlayerTank && ControlledTank)) { return; }
		
	//TODO Move towards the player
	MoveToActor(PlayerTank, AcceptanceRadius); //TODO check radius is in cm
		
	//Aim towards the player
	auto AimingComponent = ControlledTank->FindComponentByClass<UTankAimingComponent>();
	AimingComponent->AimAt(PlayerTank->GetActorLocation());

	if (AimingComponent->GetFiringState() == EFiringStatus::Locked)
	{
		AimingComponent->TankFire(); // TODO limit firing rate.
	}
	
}