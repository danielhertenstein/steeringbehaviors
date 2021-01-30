// Copyright 2020-2021 Daniel Hertenstein. All Rights Reserved.


#include "SteeringDataComponent.h"

// Sets default values for this component's properties
USteeringDataComponent::USteeringDataComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	LinearAcceleration = FVector::ZeroVector;
	AngularAcceleration = FRotator::ZeroRotator;
}

FVector USteeringDataComponent::GetLinearAcceleration() const
{
	return LinearAcceleration;
}

FRotator USteeringDataComponent::GetAngularAcceleration() const
{
	return AngularAcceleration;
}

void USteeringDataComponent::SetLinearAcceleration(FVector NewLinearAcceleration)
{
	LinearAcceleration = NewLinearAcceleration;
}

void USteeringDataComponent::SetAngularAcceleration(FRotator NewAngularAcceleration)
{
	AngularAcceleration = NewAngularAcceleration;
}
