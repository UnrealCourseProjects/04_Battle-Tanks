// Copyright EmbraceIT Ltd.

#pragma once

#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

UENUM()
enum class EFiringStatus : uint8 {Reloading, Aiming, Locked};

//Forward Declaration
class UTankBarrel; 
class UTankTurret;

// Holds barrel parameter properties and Elevate method
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLEGROUND_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UFUNCTION(BlueprintCallable, Category = "Setup")
	void Initialise(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet);

	void AimAt(FVector HitLocation, float LaunchSpeed);

protected:
	UPROPERTY(BlueprintReadOnly, Category = "State")
	EFiringStatus FiringState = EFiringStatus::Reloading;

private:
	// Sets default values for this component's properties
	UTankAimingComponent();

	UTankBarrel* Barrel = nullptr;
	UTankTurret* Turret = nullptr;

	void MoveBarrelTracking(FVector AimDirection);
};
