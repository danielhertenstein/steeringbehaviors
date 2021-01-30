// Copyright 2020-2021 Daniel Hertenstein. All Rights Reserved.

// TODO: Is this unnecessary? Looks like I'm trying to set the behavior tree?

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "SteeringAIController.generated.h"

class UBehaviorTree;

/**
 * 
 */
UCLASS()
class STEERINGBEHAVIORS_API ASteeringAIController : public AAIController
{
	GENERATED_BODY()

protected:
	virtual void OnPossess(APawn* InPawn) override;

};
