// Copyright 2020-2021 Daniel Hertenstein. All Rights Reserved.


#include "AICharacterMovementComponent.h"

#include "SteeringDataComponent.h"

void UAICharacterMovementComponent::CalcVelocity(float DeltaTime, float Friction, bool bFluid,
	float BrakingDeceleration)
{
	if (APawn* Pawn = GetPawnOwner())
	{
		if (USteeringDataComponent* SteeringData = Cast<USteeringDataComponent>(Pawn->GetComponentByClass(USteeringDataComponent::StaticClass())))
		{
			Velocity += SteeringData->GetLinearAcceleration() * DeltaTime;
			if (Velocity.Size() > GetMaxSpeed())
			{
				Velocity = Velocity.GetSafeNormal() * GetMaxSpeed();
			}
		}
	}
}

void UAICharacterMovementComponent::PhysicsRotation(float DeltaTime)
{

	FRotator CurrentRotation = UpdatedComponent->GetComponentRotation(); // Normalized

	FRotator DeltaRot = GetDeltaRotation(DeltaTime);

	FRotator DesiredRotation = CurrentRotation;
  	if (APawn* Pawn = GetPawnOwner())
  	{
  		if (USteeringDataComponent* SteeringData = Cast<USteeringDataComponent>(Pawn->GetComponentByClass(USteeringDataComponent::StaticClass())))
  		{
  			DesiredRotation += SteeringData->GetAngularAcceleration() * DeltaTime;
  		}
  	}

	if (ShouldRemainVertical())
	{
		DesiredRotation.Pitch = 0.f;
		DesiredRotation.Yaw = FRotator::NormalizeAxis(DesiredRotation.Yaw);
		DesiredRotation.Roll = 0.f;
	}
	else
	{
		DesiredRotation.Normalize();
	}
	
	// Accumulate a desired new rotation.
	const float AngleTolerance = 1e-3f;

	if (!CurrentRotation.Equals(DesiredRotation, AngleTolerance))
	{
		// PITCH
		if (!FMath::IsNearlyEqual(CurrentRotation.Pitch, DesiredRotation.Pitch, AngleTolerance))
		{
			DesiredRotation.Pitch = FMath::FixedTurn(CurrentRotation.Pitch, DesiredRotation.Pitch, DeltaRot.Pitch);
		}

		// YAW
		if (!FMath::IsNearlyEqual(CurrentRotation.Yaw, DesiredRotation.Yaw, AngleTolerance))
		{
			DesiredRotation.Yaw = FMath::FixedTurn(CurrentRotation.Yaw, DesiredRotation.Yaw, DeltaRot.Yaw);
		}

		// ROLL
		if (!FMath::IsNearlyEqual(CurrentRotation.Roll, DesiredRotation.Roll, AngleTolerance))
		{
			DesiredRotation.Roll = FMath::FixedTurn(CurrentRotation.Roll, DesiredRotation.Roll, DeltaRot.Roll);
		}

		// Set the new rotation.
		MoveUpdatedComponent( FVector::ZeroVector, DesiredRotation, /*bSweep*/ false );
	}
}
