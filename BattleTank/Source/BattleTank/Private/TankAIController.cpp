// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "Tank.h"
#include "TankAIController.h"


// Called when game starts or spawned
void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

// Calls every frame
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControlledTank = Cast <ATank>(GetPawn());
	
	if (PlayerTank)
	{
		// TODO Move towards player

		// Aim towards player
		ControlledTank->AimAt(PlayerTank->GetActorLocation());

		// Fire at the player when ready
		// ControlledTank->Fire();
	}
}