// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAmingComponent.h"
#include "TankAIController.h"
// Depends on movement component via pathfinding system

// Called when game starts or spawned
void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

// Calls every frame
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	auto ControlledTank = GetPawn();
	
	if (!ensure(PlayerTank && ControlledTank)) { return; }
	// Move towards player
	MoveToActor(PlayerTank, AcceptanceRadius);

	// Aim towards player
	auto AimingComponent = ControlledTank->FindComponentByClass<UTankAmingComponent>();
	AimingComponent->AimAt(PlayerTank->GetActorLocation());

	// Fire at the player when ready
	AimingComponent->Fire();

}