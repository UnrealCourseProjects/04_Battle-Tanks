// Copyright EmbraceIT Ltd.

#pragma once

#include "GameFramework/Pawn.h"
#include "Tank.generated.h" //Put new includes above

UCLASS()
class BATTLEGROUND_API ATank : public APawn
{
	GENERATED_BODY()

public:	
	// Sets default values for this pawn's properties
	ATank();

	// called by the engine when actor damage is dealt.
	virtual float TakeDamage (float DamageAmount, struct FDamageEvent const & DamageEvent, class AController * EventInstigator, AActor * DamageCauser) override;

private:
	UPROPERTY(EditDefaultsOnly, Category ="Setup")
	int32 StartingHealth = 100;

	UPROPERTY(VisibleAnywhere, Category ="Setup")
	int32 CurrentHealth = StartingHealth;
};
