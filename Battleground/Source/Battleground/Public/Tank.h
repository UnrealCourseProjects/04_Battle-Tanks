// Copyright EmbraceIT Ltd.

#pragma once

#include "GameFramework/Pawn.h"
#include "Tank.generated.h" //Put new includes above

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FTankDelegate);

UCLASS()
class BATTLEGROUND_API ATank : public APawn
{
	GENERATED_BODY()

public:	
	// called by the engine when actor damage is dealt.
	virtual float TakeDamage (float DamageAmount, struct FDamageEvent const & DamageEvent, class AController * EventInstigator, AActor * DamageCauser) override;
	
	//return current health as a percentage of starting health, between 0 and 1
	UFUNCTION(BlueprintPure, Category = "Health")
	float GetHealthPercent() const;

	FTankDelegate OnDeath;

private:
	// Sets default values for this pawn's properties
	ATank();

	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category ="Setup")
	int32 StartingHealth = 100;

	UPROPERTY(VisibleAnywhere, Category ="Setup")
	int32 CurrentHealth; //Initialised at BeginPlay
};
