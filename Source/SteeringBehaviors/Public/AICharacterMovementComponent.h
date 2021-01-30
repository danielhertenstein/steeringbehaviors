// Copyright 2020-2021 Daniel Hertenstein. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "AICharacterMovementComponent.generated.h"

/**
 * 
 */
UCLASS()
class STEERINGBEHAVIORS_API UAICharacterMovementComponent : public UCharacterMovementComponent
{
	GENERATED_BODY()

public:
	virtual void CalcVelocity(float DeltaTime, float Friction, bool bFluid, float BrakingDeceleration) override;

	virtual void PhysicsRotation(float DeltaTime) override;
	
};
