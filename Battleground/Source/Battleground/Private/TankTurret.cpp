// Copyright EmbraceIT Ltd.

#include "Battleground.h"
#include "TankTurret.h"

void UTankTurret::Rotate(float RelativeSpeed)
{
	RelativeSpeed = FMath::Clamp(RelativeSpeed, -1.f, 1.f);
	auto RotationChange = RelativeSpeed*MaxDegreesPerSecond*GetWorld()->DeltaTimeSeconds;
	auto NewRotation = RelativeRotation.Yaw + RotationChange;
	SetRelativeRotation(FRotator(0,NewRotation,0));
}


