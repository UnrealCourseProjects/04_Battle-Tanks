// Copyright EmbraceIT Ltd.

#pragma once

#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h" //Must be the last include

class ATank;

/**
 * 
 */
UCLASS()
class BATTLEGROUND_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable, Category = "Setup")
		ATank* GetControlledTank() const;

private:
	
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	//Start the tank moving the barrel so that a shot would hit where 
	//the crosshiar intersects the world.
	void AimTowardsCrosshairs();

	//Return an OUT parameter, true if hit landscape
	bool GetSightRayHitLocation(FVector& OutHitLocation) const;

	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;

	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;

	UPROPERTY(EditAnywhere)
	float CrossHairXLocation = 0.5;

	UPROPERTY(EditAnywhere)
	float CrossHairYLocation = 0.33333;

	UPROPERTY(EditAnywhere)
	float LineTraceRange = 1000000;
	
};
