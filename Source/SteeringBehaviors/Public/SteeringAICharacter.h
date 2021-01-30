// Copyright 2020-2021 Daniel Hertenstein. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "SteeringCharacter.h"


#include "SteeringAICharacter.generated.h"

class UAICharacterMovementComponent;
class UBehaviorTreeComponent;
class USteeringDataComponent;

/**
 * 
 */
UCLASS()
class STEERINGBEHAVIORS_API ASteeringAICharacter : public ASteeringCharacter
{
	GENERATED_BODY()

public:
    ASteeringAICharacter(const FObjectInitializer& ObjectInitializer);

protected:
	USteeringDataComponent* SteeringDataComponent;

	UPROPERTY(VisibleAnywhere)
	UBehaviorTreeComponent* BehaviorTreeComponent;

};
