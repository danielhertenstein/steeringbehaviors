// Copyright 2020-2021 Daniel Hertenstein. All Rights Reserved.


#include "BTTask_GetSeekSteering.h"

#include "AICharacterMovementComponent.h"
#include "SteeringDataComponent.h"

#include "BehaviorTree/BlackboardComponent.h"

UBTTask_GetSeekSteering::UBTTask_GetSeekSteering()
{
	NodeName = TEXT("GetSeekSteering");
}

EBTNodeResult::Type UBTTask_GetSeekSteering::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	// Get the direction to the target
	if (APawn* Pawn = Cast<APawn>(OwnerComp.GetBlackboardComponent()->GetValueAsObject(FName("SelfActor"))))
	{
		FVector TargetLocation = OwnerComp.GetBlackboardComponent()->GetValueAsVector(FName("TargetLocation"));
		FVector LinearAcceleration = TargetLocation - Pawn->GetActorLocation();

		// Give full acceleration along this direction
		if (UAICharacterMovementComponent* MovementComponent = Cast<UAICharacterMovementComponent>(Pawn->GetComponentByClass(UAICharacterMovementComponent::StaticClass())))
		{
			LinearAcceleration = LinearAcceleration.GetSafeNormal() * MovementComponent->MaxAcceleration;
		}
		else
		{
			return EBTNodeResult::Failed;
		}

		if (USteeringDataComponent* SteeringData = Cast<USteeringDataComponent>(Pawn->GetComponentByClass(USteeringDataComponent::StaticClass())))
		{
			SteeringData->SetLinearAcceleration(LinearAcceleration);
			SteeringData->SetAngularAcceleration(FRotator::ZeroRotator);
		}
		else
		{
			return EBTNodeResult::Failed;
		}
		
		return EBTNodeResult::Succeeded;
	}
	return EBTNodeResult::Failed;
}
