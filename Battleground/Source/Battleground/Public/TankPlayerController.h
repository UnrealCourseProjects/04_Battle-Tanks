// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h" //Must be the last include

/**
 * 
 */
UCLASS()
class BATTLEGROUND_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	ATank* GetControlledTank() const;

	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	//Start the tank moving the barrel so that a shot would hit where 
	//the crosshiar intersects the world.
	void AimTowardsCrosshairs();

	bool GetSightRayHitLocation(FVector& OutHitLocation) const;
	
};
