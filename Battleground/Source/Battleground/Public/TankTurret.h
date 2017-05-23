// Copyright EmbraceIT Ltd.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankTurret.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))//, hidecategories = ("collision"))
class BATTLEGROUND_API UTankTurret : public UStaticMeshComponent
{
	GENERATED_BODY()
public:
		void Rotate(float RelativeSpeed);

		UPROPERTY(EditAnywhere, Category = Setup)
			float MaxDegreesPerSecond = 45; // Sensible angle

};
