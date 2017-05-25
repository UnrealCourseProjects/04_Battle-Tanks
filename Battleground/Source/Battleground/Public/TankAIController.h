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
	
protected:
	//How close can the enemy tank get.
	UPROPERTY(EditAnywhere, Category = "Setup") // Consider EditDefaultOnly
	float AcceptanceRadius = 8000;

private:
	
	virtual void BeginPlay() override;

	virtual void SetPawn(APawn* InPawn) override;

	UFUNCTION()
	void OnPossessedTankDeath();

	virtual void Tick(float DeltaTime) override;
};
