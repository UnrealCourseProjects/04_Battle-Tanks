// Copyright EmbraceIT Ltd.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * Tank Track is used to set maxium forward force and apply forces to the tank.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))//, hidecategories = ("collision"))
class BATTLEGROUND_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = Input)
	void SetThrottle(float Throttle);
	
	// max force per track
	UPROPERTY(EditDefaultsOnly)
		float TrackMaxDrivingForce = 40000000;
private:
	UTankTrack();

	virtual void BeginPlay() override;

	UFUNCTION()
	void OnHit(UPrimitiveComponent * HitComponent, AActor * OtherActor, UPrimitiveComponent * OhterComponent, FVector NormalImpulse, const FHitResult & Hit);

	void ApplySidewaysForce();

	void DriveTrack();

	float CurrentThrottle = 0;

};
