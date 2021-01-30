// Copyright 2020-2021 Daniel Hertenstein. All Rights Reserved.


#include "SteeringAICharacter.h"

#include "SteeringDataComponent.h"

#include "AICharacterMovementComponent.h"
#include "BehaviorTree/BehaviorTreeComponent.h"

ASteeringAICharacter::ASteeringAICharacter(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer.SetDefaultSubobjectClass<UAICharacterMovementComponent>(CharacterMovementComponentName))
{
    SteeringDataComponent = CreateDefaultSubobject<USteeringDataComponent>(TEXT("SteeringDataComponent"));

    BehaviorTreeComponent = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviorTreeComponent"));
}