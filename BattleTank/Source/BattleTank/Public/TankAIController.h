// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AIController.h"
#include "TankAIController.generated.h" // Must be last?

// Forward Declarations

/**
 * 
 */

UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()

private:
	virtual void Tick(float DeltaSeconds) override;
	
	virtual void BeginPlay() override;

	// How close to get to the player before stopping
	float AcceptanceRadius = 5000.0f;
};