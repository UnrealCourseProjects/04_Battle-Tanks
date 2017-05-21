// Copyright EmbraceIT Ltd.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))//, hidecategories = ("collision"))
class BATTLEGROUND_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	// -1 is max downward speed, and +1 is max up movement
	void Elevate(float RelativeSpeed);
	
private:
	UPROPERTY(EditAnywhere, Category = Setup)
		float MaxDegreesPerSecond = 10; // Sensible angle

	UPROPERTY(EditAnywhere, Category = Setup)
		float MaxElevationDegrees = 30; // Sensible high elevation

	UPROPERTY(EditAnywhere, Category = Setup)
		float MinElevationDegrees = 0; // Sensible low elevation
};
