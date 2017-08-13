// Copyright EmbraceIT Ltd.

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
	auto TankForwardDirection = GetOwner()->GetActorForwardVector().GetSafeNormal();
	auto AIForwardIntention = MoveVelocity.GetSafeNormal();
	auto ForwardThrow = FVector::DotProduct(TankForwardDirection, AIForwardIntention);
	auto TurnThrow = FVector::CrossProduct(TankForwardDirection, AIForwardIntention).Z;

	MoveForward(ForwardThrow);
	RotateClockwise(TurnThrow);
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