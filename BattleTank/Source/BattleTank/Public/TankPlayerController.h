// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h" // <- Must be the last include!

// Forward Declaration
class ATank;

/**
 * 
 */

UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	ATank* GetControlledTank() const;
	
	virtual void BeginPlay() override;

private:
	
	void AimTowardsCrosshair();

	// Return an OUT parameter, true if hit landscape
	bool GetSightRayHitLocation(FVector& HitLocation) const;

	UPROPERTY(EditAnywhere)
	float CrosshairXLocation = 0.5;

	UPROPERTY(EditAnywhere)
	float CrosshairYLocation = 0.5;

	UPROPERTY(EditAnywhere)
	float LineTraceRange = 1000000; // << unit numbers in Unreal are in Centimeters 10km = 1,000,000cm

	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;
	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;


};