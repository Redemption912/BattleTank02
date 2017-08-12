// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankTrack.h"
#include "TankMovementComponent.h"

void UTankMovementComponent::Initialize(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet)
{
	if (!LeftTrackToSet || !RightTrackToSet) { return; }
	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;
}

void UTankMovementComponent::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed)
{
	// No need to call Super as we're replacing the functionality
	auto TankName = GetOwner()->GetName();
	auto MoveVelocityString = MoveVelocity.ToString();
	UE_LOG(LogTemp, Warning, TEXT("%s moving to %s"), *TankName, *MoveVelocityString);
}

void UTankMovementComponent::MoveForward(float Axis)
{
	if (!LeftTrack || !RightTrack) { return; }
	LeftTrack->SetThrottle(Axis);
	RightTrack->SetThrottle(Axis);
}

void UTankMovementComponent::MoveBackward(float Axis)
{
	if (!LeftTrack || !RightTrack) { return; }
	LeftTrack->SetThrottle(Axis);
	RightTrack->SetThrottle(Axis);
}

void UTankMovementComponent::RotateClockwise(float Axis)
{
	if (!LeftTrack || !RightTrack) { return; }
	LeftTrack->SetThrottle(Axis);
	RightTrack->SetThrottle(-Axis);
}