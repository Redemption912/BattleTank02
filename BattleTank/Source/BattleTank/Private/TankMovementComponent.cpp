// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankMovementComponent.h"



void UTankMovementComponent::MoveForward(float Axis)
{
	UE_LOG(LogTemp, Warning, TEXT("Axis Throttle: %f"), Axis)
}

void UTankMovementComponent::MoveBackward(float Axis)
{
	UE_LOG(LogTemp, Warning, TEXT("Axis Throttle: %f"), Axis)
}