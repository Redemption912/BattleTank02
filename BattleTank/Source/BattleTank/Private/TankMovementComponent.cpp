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