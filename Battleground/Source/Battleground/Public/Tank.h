// Copyright EmbraceIT Ltd.

#pragma once

#include "GameFramework/Pawn.h"
#include "Tank.generated.h" //Put new includes above

// Forward declarations
class UTankBarrel;
class UTankTurret;
class AProjectile;
class UTankAimingComponent;
class UTankMovementComponent;

UCLASS()
class BATTLEGROUND_API ATank : public APawn
{
	GENERATED_BODY()

public:
	void AimAt(FVector HitLocation);


	UFUNCTION(BlueprintCallable)
		void TankFire();
	
protected:
	UPROPERTY(BlueprintReadOnly)
	UTankAimingComponent* TankAimingComponent = nullptr;
	
	UPROPERTY(BlueprintReadOnly)
	UTankMovementComponent* TankMovementComponent = nullptr;
	

private:	
	// Sets default values for this pawn's properties
	ATank();
	
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	TSubclassOf<AProjectile>ProjectileBlueprint;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float LaunchSpeed = 4000; 

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
		float ReloadTimeInSeconds = 3;
	
	double LastFireTime = 0;

	UTankBarrel* Barrel = nullptr; //TODO remove
};
