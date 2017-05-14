// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent), hidecategories = ("collision"))
class BATTLEGROUND_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	void Elevate(float DegreesPerSecond);
	
private:
	UPROPERTY(EditAnywhere, Category = Setup)
		float MaxDegreesPerSecond = 20; // Sensible angle

	UPROPERTY(EditAnywhere, Category = Setup)
		float MaxElevationDegrees = 30; // Sensible high elevation

	UPROPERTY(EditAnywhere, Category = Setup)
		float MinElevationDegrees = 0; // Sensible low elevation
};
