// Copyright EmbraceIT Ltd.
#pragma once

#include "AIController.h"
#include "TankAIController.generated.h"
/**
 * 
 */
UCLASS()
class BATTLEGROUND_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
private:
	
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	//How close can the enemy tank get.
	float AcceptanceRadius = 3000;
};
