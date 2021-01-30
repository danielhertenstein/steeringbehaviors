// Copyright 2020-2021 Daniel Hertenstein. All Rights Reserved.

// TODO: Might be unnecessary as I'm using the CharacterMovementComponent for this

#include "BTTask_UpdateKinematics.h"

UBTTask_UpdateKinematics::UBTTask_UpdateKinematics()
{
	NodeName = TEXT("UpdateKinematics");
}

EBTNodeResult::Type UBTTask_UpdateKinematics::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	//  Update the position and orientation
	// position *= velocity * time
	// orientation *= rotation * time

	// and the velocity or rotation
	// velocity *= steering.linear * time
	// rotation *= steering.angular * time

	// Check for speeding and clip
	// if velocity.length() > maxSpeed:
	//	velocity.normalize()
	//	velocity *= max_speed
	
	return EBTNodeResult::Succeeded;
}
